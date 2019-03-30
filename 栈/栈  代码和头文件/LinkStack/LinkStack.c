#include <stdio.h>
#include <stdlib.h>
#include "../head/LinkStack.h"
#include "../head/linkstack_funtion.h"

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s-> top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (s->top == NULL)
		return ERROR;
	s-> count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if (s-> count == 0)
		return ERROR;
	else
		return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	if(s == NULL)
		return ERROR;
	*e = s-> top-> data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s)   //���ջ
{
	LinkStackPtr pre;
	if (s == NULL)
		return ERROR;
	while (s-> top != NULL){
		pre = s-> top-> next;
		free(s-> top);
		s-> top = pre;
	}
	s-> count = 0;
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)   //����ջ
{
	LinkStackPtr pre;
	if (s == NULL)
		return ERROR;
	while (s-> top != NULL){
		pre = s-> top-> next;
		free(s-> top);
		s-> top = pre;
	}
	free(s-> top);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	if (s == NULL)
		return ERROR;
	*length = s-> count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	StackNode *p;
	if(s == NULL)
		return ERROR;
	else if(s-> count == 0){
		s-> top-> data = data;
		s-> top-> next = NULL;
	}else {
		p = (StackNode*)malloc(sizeof(StackNode));
		p-> data = data;
		p-> next = s-> top;
		s-> top = p;
	}
	s-> count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	LinkStackPtr pre;
	if(s == NULL || s->count == 0)
		return ERROR;
	pre = s-> top->next;
	*data = s-> top-> data;
	free(s-> top);
	s-> top = pre;
	s-> count--;
	return SUCCESS;
}




