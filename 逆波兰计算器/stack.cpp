//存储字符的堆栈
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
////定义结构体
//typedef struct node {
//	char data;
//	stack next;
//}*stack;
////堆栈操作
//void Init(stack &L);   //初始化
//bool IsEmpty(stack &L); //判断堆栈是否为空
//void Push(char x, stack &L);//压入数据
//char Pop(stack &L);  //弹出数据
//函数实现
void Init(stack &L)   //初始化
{
	L = (stack)malloc(sizeof(struct node));
	L->next = NULL;
}
bool IsEmpty(stack &L) //判断堆栈是否为空
{
	if (L->next == NULL)
		return true;
	else
		return false;
}
void Push(char x, stack &L)//压入数据(头插)
{
	stack p = (stack)malloc(sizeof(struct node));
	p->data = x;
	p->next = L->next;
	L->next = p;
}
char Pop(stack &L)  //弹出数据(头删)
{
	if (IsEmpty(L))
		return ERROR;
	char temp = L->next->data;
	stack p = L->next;
	L->next = p->next;
	free(p);
	return temp;
}