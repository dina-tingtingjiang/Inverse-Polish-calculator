#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"operation.h"
#define MAX 30
int main(void)
{
	char infix[MAX], suffix[MAX], print[MAX];
	while (1) {
		printf("请输入中缀表达式:");
		gets_s(infix);
		if (!convert(infix, suffix, print)) {
			printf("输入参数错误!请重新输入!\n");
			continue;
		}
		else {
			printf("该中缀表达式的后缀表达式为:%s\n", print);
			printf("该表达式的结果为:%d\n", operation(suffix));
			break;
		}
	}
	system("pause");
}