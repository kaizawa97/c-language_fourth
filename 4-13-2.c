#include <stdio.h>
#define MAXLINE 1024

void reverse(char s[]);

int main()
{
	char s[MAXLINE] = "abcd";
	reverse(s);
	printf("%s\n", s);
}

void reverse(char s[])
{
	static int i = 0;
	static int j = 0;
	int temp = 0;
	char c = s[++j];
	if (c != '\0')
	{
		reverse(s);
		s[i++] = c;
	}
	if (temp == 0)
	{
		i = 0;
		j = 0;
	}
}
