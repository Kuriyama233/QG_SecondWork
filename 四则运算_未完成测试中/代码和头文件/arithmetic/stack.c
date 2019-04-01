#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/stack.h"

void get_string(char *str, LinkStack *Num)
{
	char *start, *end;
	char s[SIZE];
	Data data;
	str = (char*)malloc(SIZE * sizeof(char));
	gets(str+1);
	if(*str+1 == '-' || *str+1 == '+'){
		*str = '0';
	}else{
		str++;
	}
	while (*str != '\0'){
//			printf("%d",*str);getchar();
		if(*str == ' '){
			str++;
			continue;
		}
		else if(isnum){
			start = str;
			do{
				str++;
				if(*str=='\0')break;
			}while(!issign);
			end = str;
			memcpy(s, start, end-start);
			data.unit.num = atof(s);
//			printf("%lf",data.unit.num);
//			getchar();
			data.judge = 1;
			pushLStack(Num, data);
//			printf("%d",data.judge);getchar();
		}
		else if(issign){
			data.unit.sign = *str;
			data.judge = 0;
			pushLStack(Num,data);
			str++;
		}
	}
	transposition(--Num);
}

LinkStack* transposition(LinkStack *Num)
{
	LinkStack *p;
	p = Num;
	Data data;
	initLStack(Num);
	while(p->count != 0){
		popLStack(p,&data);
		pushLStack(Num,data);
	}
	return Num;
}

Status pushLStack(LinkStack *s,Data data)   //入栈
{
	StackNode *p;
	if(s == NULL)
		return ERROR;
	else if(s-> count == 0){
		if(data.judge){
			s->top->elem.unit.num = data.unit.num;
			s->top->elem.judge = 1;
		}else{
			s->top->elem.unit.sign = data.unit.sign;
			s->top->elem.judge = 0;
		}
		s-> top-> next = NULL;
	}else {
		p = (StackNode*)malloc(sizeof(StackNode));
		if(data.judge){
			p->elem.unit.num = data.unit.num;
			p->elem.judge = 1;
		}else{
			p->elem.unit.sign = data.unit.sign;
			p->elem.judge = 0;
		}
		p-> next = s-> top;
		s-> top = p;
	}
	s-> count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,Data *data)   //出栈
{
	LinkStackPtr pre;
	if(s == NULL || s->count == 0)
		return ERROR;
	pre = s-> top->next;
	if(s->top->elem.judge){
		data->unit.num = s->top->elem.unit.num;
		data->judge = 1;
	}else{
		data->unit.sign = s->top->elem.unit.sign;
		data->judge = 0;
	}
	free(s-> top);
	s-> top = pre;
	s-> count--;
	return SUCCESS;
}

Status initLStack(LinkStack *s)   //初始化
{
	s-> top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (s->top == NULL)
		return ERROR;
	s-> count = 0;
	return SUCCESS;
}


