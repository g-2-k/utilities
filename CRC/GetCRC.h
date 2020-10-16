# ifndef GET_CRC_HEADER
# define GET_CRC_HEADER

unsigned int Reflct(unsigned int ref, unsigned char i);
void Init_CRC32_Table();
unsigned int getcrc(unsigned char *bfr, unsigned int len);

# endif