#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"operation.h"
#define MAX 30
int main(void)
{
	char infix[MAX], suffix[MAX], print[MAX];
	while (1) {
		printf("��������׺���ʽ:");
		gets_s(infix);
		if (!convert(infix, suffix, print)) {
			printf("�����������!����������!\n");
			continue;
		}
		else {
			printf("����׺���ʽ�ĺ�׺���ʽΪ:%s\n", print);
			printf("�ñ��ʽ�Ľ��Ϊ:%d\n", operation(suffix));
			break;
		}
	}
	system("pause");
}