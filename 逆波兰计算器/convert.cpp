//中缀表达式转换后缀表达式
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"operation.h"

bool convert(char*Infix, char*Suffix, char*Print)
{
	stack Op;
	Init(Op);
	char *inf = Infix;
	char *suf = Suffix;
	char *print = Print;
	while (*inf != '\0')
	{
		if (*inf >= '0'&&*inf <= '9')
		{
			while (*inf >= '0'&&*inf <= '9') {
				*suf++ = *print++ = *inf++;
			}
			*suf++ = '#';
		}
		else if (*inf == '+' || *inf == '-')
		{
			int temp = Pop(Op);
			while (temp != ERROR) {
				if (temp == '(') {
					Push(temp, Op);
					break;
				}
				else if (temp == '*' || temp == '/' || temp == '+' || temp == '-') {
					*suf++ = *print++ = temp;
				}
				temp = Pop(Op);
			}
			Push(*inf++, Op);
		}
		else if (*inf == '/' || *inf == '*')
		{
			int temp = Pop(Op);
			while (temp != ERROR) {
				if (temp == '(' || temp == '+' || temp == '-') {
					Push(temp, Op);
					break;
				}
				else if (temp == '*' || temp == '/') {
					*suf++ = *print++ = temp;
				}
				temp = Pop(Op);
			}
			Push(*inf++, Op);
		}
		else if (*inf == '(') {
			Push(*inf++, Op);
		}
		else if (*inf == ')') {
			int temp = Pop(Op);
			while (temp != '('&&temp != '\0') {
				*suf++ = *print++ = temp;
				temp = Pop(Op);
			}
			if (temp == '\0')
				return false;
			else
				*inf++;
		}
		else
			return false;
	}
	int temp = Pop(Op);
	while (temp != ERROR) {
		*suf++ = *print++ = temp;
		temp = Pop(Op);
	}
	*suf = '\0';
	*print = '\0';
	return true;
}