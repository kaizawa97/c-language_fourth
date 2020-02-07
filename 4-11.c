// 4-11 ungetchを必要としないようにgetopを変更せよ
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

//char buf[BUFSIZE]; Because this problem is not use global varieble.
//int bufp = 0;

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
			break;
		default:
			if (flag == 1)
			{
				int search;
				for (search = 0; search <= MAXCHAR; search++)
				{
					if (i[search] == type)
					{
						push(nm[search]);
						break;
					}
				}
			}
			else if ('a' <= type && type <= 'z')
			{
				i[number] = type;
			}
			else
			{
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
	int i, c, getflag;
	static char buf[BUFSIZE];
	static int bufp = 0;

	while ((s[0] = c = (bufp > 0) ? buf[--bufp] : getchar()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	i = 0;

	if (!isdigit(c) && c != '.')
	{
		return c;
	}
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()))
			;
	}
	if (c == '.')
	{
		while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()))
			;
	}
	s[i] = '\0';

	if (c != EOF)
	{
		if (bufp >= BUFSIZE)
		{
			printf("getop: too many characters\n");
		}
		else
		{
			buf[bufp++] = c;
		}
	}
	return NUMBER;
}
