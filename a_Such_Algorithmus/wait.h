#include <time.h>

void wait_milliseconds(int d_milliseconds) 		/* Zeitverzoegerung */
{
	clock_t endwait;
	endwait = clock() + d_milliseconds * CLK_TCK / 1000;
	while (clock() < endwait) {}
}
