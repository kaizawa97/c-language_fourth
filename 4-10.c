
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//mainの変数群
#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

//push/popの変数群
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

//getopの変数群
int getch(void);
void ungetch(int);

//(un)getchの変数群
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

#define MAXCHAR 26

//getlineの変更点です。
#define MAXLINE 1024
int getline01(char s[], int lim);
int linecount;
char line[MAXLINE] = "";

int main()
{
	int type, number, charnumber;
	int flag = 0;
	double op2;
	char s[MAXOP];
	char i[MAXCHAR];
	char nm[MAXCHAR];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case 'W':
			charnumber = pop();
			nm[number] = charnumber;
			++number;
			break;
		case 'R':
			printf("OB");
			flag = 1;
			break;
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
			{
				printf("e");
				push(pop() / op2);
			}
			else
			{
				printf("error: zero divisor\n");
			}
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			{
				printf("f");
				int opopfrom = pop();
				int opopto = op2;
				push(opopfrom % opopto);
			}
			else
			{
				printf("error: zero divisor\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case '\0':
			printf("d");
			break;
		default:
			if (flag == 1)
			{
				int search;
				for (search = 0; search <= MAXCHAR; search++)
				{
					if (i[search] == type)
					{
						printf("g");
						push(nm[search]);
						break;
					}
				}
			}
			else if ('a' <= type && type <= 'z')
			{
				printf("h");
				i[number] = type;
			}
			else
			{
				printf("i");
				printf("error: unknown command %s\n", s);
			}
			break;
		}
	}
	return 0;
}

//pushとpopの部分の構成
void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

//次の演算子あるいは数値の日演算数をとってくる
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (c == '-' && !isdigit(s[++i] = c = getch()))
	{
		ungetch(c);
		return '-';
	}
	if (!isdigit(c) && c != '.')
	{
		return c;
	}
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.')
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if (c != EOF)
	{
		ungetch(c);
	}
	return NUMBER;
}

//バッファあたりbufたちの関数
int arraycount = 0;
int getch(void)
{
	if (bufp > 0)
	{
		return buf[--bufp];
	}
	if (line[arraycount] == '\0')
	{
		arraycount = 0;
		getline01(line, MAXLINE);
	}
	return line[arraycount++];
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
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
