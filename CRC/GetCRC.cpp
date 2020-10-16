# include "GetCRC.h"
# include <stdlib.h>

unsigned int *crc32_table;

unsigned int Reflct(unsigned int ref, unsigned char i)
{
	unsigned int vlu(0);
	do {
		i--;
		if(ref & 1)
			vlu |= 1 << i;
		ref >>= 1;
	} while(i);
	return vlu;
}

void Init_CRC32_Table()
{
	unsigned int ulPolynomial = 0x04c11db7;
	for(unsigned int i = 0; i <= 0xFF; i++)
	{
		crc32_table[i]=Reflct(i, 8) << 24;
		for (unsigned int j = 0; j < 8; j++)
			crc32_table[i] = (crc32_table[i] << 1) ^ (crc32_table[i] & (1 << 31) ? ulPolynomial : 0);
		crc32_table[i] = Reflct(crc32_table[i], 32);
	}
}

unsigned int getcrc(unsigned char *bfr, unsigned int len)
{
	crc32_table = new unsigned int [256];
	if(!crc32_table)
		exit(-6);
	Init_CRC32_Table();

	unsigned int crc(0xffffffff);

	while(len--)
		crc = (crc >> 8) ^ crc32_table[(crc & 0xFF) ^ *bfr++];

	delete crc32_table;
	return (crc^0xffffffff);
}
