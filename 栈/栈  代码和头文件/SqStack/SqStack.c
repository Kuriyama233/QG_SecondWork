#include "../head/SqStack.h"
#include "../head/funcion.h"
#include <stdio.h>
#include <stdlib.h>
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
	s-> elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if (s-> elem == NULL)
		return ERROR;
	s-> top = -1;
	s-> size = sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if (s-> top == -1)
		return ERROR;
	else
		return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if (s-> top == -1)
		return ERROR;
	*e = s-> elem[s-> top];
	return SUCCESS;
}

Status clearStack(SqStack *s)   //清空栈
{
	if (s == NULL)
		return ERROR;
	for (int i=0; i<s-> top; i++)
		s-> elem[i] = 0;
	s-> top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)  //销毁栈
{
	if (s == NULL)
		return ERROR;
	free(s->elem);
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	if (s == NULL)
		return ERROR;
	*length = s-> top+1;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if (s == NULL || s-> top == s-> size - 1)
		return ERROR;
	s-> top++;
	s-> elem[s-> top] = data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)   //出栈
{
	if (s == NULL || s->top == -1)
		return ERROR;
	*data = s-> elem[s-> top];
	s-> top--;
	return SUCCESS;
}


