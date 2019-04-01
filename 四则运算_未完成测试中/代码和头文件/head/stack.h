#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define SIZE 50
#define isnum (*str>='0'&&*str<='9')
#define issign (*str=='+'||*str=='-'||*str=='*'||*str=='/'||*str=='('||*str==')')
#define ispoint (*str=='.')

typedef struct data{
	int judge;
	union {
		char sign;
		double num;
	}unit;
}Data;


typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;


typedef  struct StackNode
{
	Data elem;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;

void get_string(char *str, LinkStack *Num);
LinkStack* transposition(LinkStack *Num);
Status initLStack(LinkStack *s);
Status pushLStack(LinkStack *s,Data data);
Status popLStack(LinkStack *s,Data *data);




#endif // STACK_H_INCLUDED
