//�洢�ַ��Ķ�ջ
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
////����ṹ��
//typedef struct node {
//	char data;
//	stack next;
//}*stack;
////��ջ����
//void Init(stack &L);   //��ʼ��
//bool IsEmpty(stack &L); //�ж϶�ջ�Ƿ�Ϊ��
//void Push(char x, stack &L);//ѹ������
//char Pop(stack &L);  //��������
//����ʵ��
void Init(stack &L)   //��ʼ��
{
	L = (stack)malloc(sizeof(struct node));
	L->next = NULL;
}
bool IsEmpty(stack &L) //�ж϶�ջ�Ƿ�Ϊ��
{
	if (L->next == NULL)
		return true;
	else
		return false;
}
void Push(char x, stack &L)//ѹ������(ͷ��)
{
	stack p = (stack)malloc(sizeof(struct node));
	p->data = x;
	p->next = L->next;
	L->next = p;
}
char Pop(stack &L)  //��������(ͷɾ)
{
	if (IsEmpty(L))
		return ERROR;
	char temp = L->next->data;
	stack p = L->next;
	L->next = p->next;
	free(p);
	return temp;
}