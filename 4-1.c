#include <stdio.h>
#include <string.h>
#define MAXLINE 1024

int getline01(char s[], int lim);
int strindex(char source[], char searchfor[]);
void reverse(char s[]);

char pattern[] = "Love!"; //探すべきパターン

int main()
{
	int reverse, count;
	char line[MAXLINE];
	int found = 0;

	while ((count = getline01(line, MAXLINE)) > 0)
	{
		if ((reverse = strindex(line, pattern)) >= 0)
		{
			printf("%d\n", count - reverse);
			found++;
		}
	}
	return found;
}

int strindex(char s[], char t[])
{
	int i, j, k; //kの数はパターンの数です。 iの数は逆から見た数です。

	reverse(s);
	reverse(t);

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
		{
			return i + k;
		}
	}
	return -1;
}

int getline01(char s[], int lim)
{
	int c, i;

	i = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
	{
		s[i++] = c;
	}
	if (c == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
