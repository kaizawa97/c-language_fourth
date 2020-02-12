#include <stdio.h>
#define swap(t,x,y) { t tmp;tmp = x;x = y; y = tmp; }
int main()
{
	int x, y;
	x = 5;
	y = 2;
	swap(int, x, y);
	printf("x = %d y = %d", x, y);
}
