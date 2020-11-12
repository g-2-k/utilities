# include "FileName.h"

void fileName(char* fnm[], std::ofstream out) {
	unsigned int i, j;
	unsigned int lmt = 0;
	char* nam;

	for (i = 0;; i++)
		if (fnm[1][i] == '\\')
			lmt = i + 1;
		else if (fnm[1][i] == NULL)
			break;

	i -= lmt;
	nam = new char[i];
	if (!nam)
		exit(-5);

	for (j = 0; j < i; j++)
		nam[j] = fnm[1][lmt + j];

	out.put((unsigned char)i);
	out.write(nam, i);
	delete nam;
}
