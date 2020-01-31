#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double atof(char s[]);

int main()
{
	char s[1024] = "1234.56e2";
	printf("%f\n", atof(s));
}
double atof(char s[])
{
	double val = 0, power = 1;
	int i, sign, e, esign = 0;

	for (i = 0; isspace(s[i]); i++) //空白を飛ばす
		;
	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
	{
		i++;
	}

	for (; isdigit(s[i]); i++) //整数部分の処理
	{
		val = 10.0 * val + s[i] - '0';
	}
	if (s[i] == '.')
	{
		i++; //数字ではないので一つ進めます
	}

	for (; isdigit(s[i]); i++) //小数点のところの処理
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
		esign = (s[i] == '-') ? -1 : 1; //-だったら[-1]をかける。
		if (s[i] == '+'|| s[i] == '-')
		{
			i++; //これ以外だったら一つ追加しなくて良い
		}		//具体例としては[e1]

		for (; isdigit(s[i]); i++)
		{
			e = e * 10 + s[i] - '0'; //自乗する数値をここで確定させる
		}
		e *= esign; //上のesignをここで掛けます
		printf("%d\n",e);
	}
	return sign * val * pow(10,e) / power;
}
