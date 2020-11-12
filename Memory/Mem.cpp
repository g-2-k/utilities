# include "Mem.h"

mem::mem(unsigned char *tpt)
{
	ptr = tpt;
	buffer = *ptr;
	ptr++;
	iBit = 0;
};

unsigned int mem::read(signed int bln)
{
	unsigned int dat = 0;

	buffer <<= iBit;
	buffer >>= iBit;

	while(bln > 0)
	{
		if(iBit == 8) {
			buffer = *ptr;
			ptr++;
			iBit = 0;
		}
		bln -= (8-iBit);
		if(bln > 0) {
			dat |= ((unsigned int)buffer << bln);
			iBit = 8;
		}
		else {
			dat |= ((unsigned int)buffer >> (-1*bln));
			iBit = 8+bln;
		}
	}

	return dat;
};

void mem::read_flush()
{
	if(iBit == 8)
	{
		buffer = *ptr;
		ptr++;
		iBit = 0;
	}
}

void mem::write(unsigned int dat, signed int bln)
{
	ptr--;
	while(bln > 0)
	{
		bln -= (8-iBit);
		if(bln > 0)
		{
			buffer |= (unsigned char)(dat >> bln);
			iBit = 8;
		}
		else
		{
			buffer |= (unsigned char)(dat << (-1*bln));
			iBit = 8+bln;
		}
		if(iBit == 8)
		{
			*ptr = buffer;
			ptr++;
			buffer = 0;
			iBit = 0;
		}
	}
};

void mem::write_flush()
{
	if(iBit)
	{
		*ptr = buffer;
		buffer = 0;
		iBit = 0;
		ptr++;
	}
}
