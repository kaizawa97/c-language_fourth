#include <stdio.h>
int swap(int a, int b);

int main () 
{
	int x,y;
	x = 11;
	y = 2;
	swap(x,y);
	printf("x = %d y = %d",x,y);
}

int swap(int a, int b)
{
	int copy = 0;
	copy = a;
	a = b;
	b = copy;
	return a,b; //二つの引数をreturnすることは無理。
	//この場合には複数関数作らないといけないかな？
}

