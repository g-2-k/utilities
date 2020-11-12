# include "WriteData.h"

void writeData(unsigned int dat, signed int bln, std::ofstream& out)
{
	static unsigned char buf = 0;
	static unsigned int iBit = 0;

	while (bln > 0) {
		bln -= (8 - iBit);
		if (bln > 0) {
			buf |= (unsigned char)(dat >> bln);
			iBit = 8;
		}
		else {
			buf |= (unsigned char)(dat << (-1 * bln));
			iBit = 8 + bln;
		}
		if (iBit == 8) {
			out.write((const char*)&buf, sizeof buf);
			buf = 0;
			iBit = 0;
		}
	}
}