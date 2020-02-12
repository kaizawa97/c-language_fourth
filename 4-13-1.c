#include <stdio.h>
#include <string.h>
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
	int c;
	static int i = 0;
	int j = strlen(s) - 1 - i;

	if (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		reverse(s);
		i = 0;
	}
}
