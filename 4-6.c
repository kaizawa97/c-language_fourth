#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//mainに関する定義・変数宣言
#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

//push・popに関数する定義・変数宣言
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

//getopに関数する定義・変数宣言
int getch(void);
void ungetch(int);

//(un)getchに関数する定義・変数宣言
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

#define MAXCHAR 26

int main()
{
	int type, number, charnumber, flag;
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
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
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
