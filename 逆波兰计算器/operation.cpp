//用获得的后缀表达式求出结果!
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"operation.h"

int operation(char*Suffix)
{
	stack Num;
	Init(Num);
	char *suf = Suffix;
	while (*suf != '\0')
	{
		if (*suf >= '0'&&*suf <= '9')
		{
			int d = 0;
			while (*suf >= '0'&&*suf <= '9') {
				d = 10 * d + *suf - '0';
				*suf++;
			}
			Push(d, Num);
			*suf++;
		}
		if (*suf == '+')
		{
			int a, b, c;
			b = Pop(Num);
			a = Pop(Num);
			c = a + b;
			Push(c, Num);
			*suf++;
		}
		if (*suf == '+')
		{
			int a, b, c;
			b = Pop(Num);
			a = Pop(Num);
			c = a + b;
			Push(c, Num);
			*suf++;
		}
		if (*suf == '-')
		{
			int a, b, c;
			b = Pop(Num);
			a = Pop(Num);
			c = a - b;
			Push(c, Num);
			*suf++;
		}
		if (*suf == '*')
		{
			int a, b, c;
			b = Pop(Num);
			a = Pop(Num);
			c = a * b;
			Push(c, Num);
			*suf++;
		}
		if (*suf == '/')
		{
			int a, b, c;
			b = Pop(Num);
			a = Pop(Num);
			c = a / b;
			Push(c, Num);
			*suf++;
		}
	}
	return Pop(Num);
}