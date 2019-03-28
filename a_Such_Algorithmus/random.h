// Remembering to define _CRT_RAND_S prior  
// to inclusion statement.  


#ifndef _INC_STDLIB

#define _CRT_RAND_S
#include <stdlib.h> 

int getrandom_int(int min, int max) {
	int zufallszahl, bereichsbreite;
	unsigned int number;
	errno_t err;

	err = rand_s(&number);
	bereichsbreite = max - min + 1;
	zufallszahl = (int)((double)number / ((double)UINT_MAX + 1) * bereichsbreite) + min;
	return zufallszahl;
}


double getrandom_double(double min, double max) {
	double zufallszahl, bereichsbreite;
	unsigned int number;
	errno_t err;

	err = rand_s(&number);
	bereichsbreite = max - min;
	zufallszahl = ((double)number / ((double)UINT_MAX + 1) * bereichsbreite) + min;
	return zufallszahl;
}

#else

int getrandom_int(int min, int max) 
{
	printf("\n\nDie headerdatei random.h konnte nicht richtig geladen werden!\n Hast du die stdlib.h vielleicht vorher includiert?\n\n");

	return NULL;
}

double getrandom_double(double min, double max) 
{
	printf("\n\nDie headerdatei random.h konnte nicht richtig geladen werden!\nHast du die stdlib.h vielleicht vorher includiert?\n\n");

	return NULL;
}


#endif // ! _INC_STDLIB

