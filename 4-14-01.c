#include <stdio.h>
#define swap(t,x,y) { tmp = x; x = y;  y = tmp; }

int main()
{
	int x, y;
	x = 11;
	y = 2;
	swap(int, x, y)
	printf("x = %d y = %d", x, y);
}
