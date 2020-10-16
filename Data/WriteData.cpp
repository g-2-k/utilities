# include "WriteData.h"

void writeData(unsigned int dat, signed int bln, std::ofstream& out)
{
	static unsigned char buf = 0;
	static unsigned int bst = 0;

	while(bln > 0) {
		bln -= (8-bst);
		if(bln > 0) {
			buf |= (unsigned char)(dat >> bln);
			bst = 8;
		}
		else {
			buf |= (unsigned char)(dat << (-1*bln));
			bst = 8+bln;
		}
		if(bst == 8) {
			out.write((const char *)&buf, sizeof buf);
				buf = 0;
			bst = 0;
		}
	}
}