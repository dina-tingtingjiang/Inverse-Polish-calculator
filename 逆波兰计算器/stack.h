#define ERROR -1
typedef struct node {
	char data;
	struct node *next;
}*stack;
//��ջ����
void Init(stack &L);   //��ʼ��
bool IsEmpty(stack &L); //�ж϶�ջ�Ƿ�Ϊ��
void Push(char x, stack &L);//ѹ������
char Pop(stack &L);  //��������
