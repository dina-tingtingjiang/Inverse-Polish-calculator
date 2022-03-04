#define ERROR -1
typedef struct node {
	char data;
	struct node *next;
}*stack;
//堆栈操作
void Init(stack &L);   //初始化
bool IsEmpty(stack &L); //判断堆栈是否为空
void Push(char x, stack &L);//压入数据
char Pop(stack &L);  //弹出数据
