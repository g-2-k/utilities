# ifndef MEM_HEADER
# define MEM_HEADER

struct mem
{
	unsigned char *ptr;
	unsigned char buffer;
	unsigned int bst;

	mem(unsigned char *);
	unsigned int read(signed int);
	void write(unsigned int, signed int);
};

# endif