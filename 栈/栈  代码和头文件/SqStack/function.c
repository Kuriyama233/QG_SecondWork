#include "../head/SqStack.h"
#include "../head/funcion.h"
#include <stdio.h>
#include <stdlib.h>

Status save_get(ElemType *choice)
{
	ElemType status = ERROR;
	if(scanf("%d",choice)){
		status = SUCCESS;
	}
	while (getchar() != '\n');

	return status;
}


void initial_interface()
{
	printf("\n\n\n\n\n"
	"\t\t\t|*******************************|\n"
	"\t\t\t|*         创建一个栈          *|\n"
	"\t\t\t|*   1、初始化一个栈           *|\n"
	"\t\t\t|*   2、退出程序               *|\n"
	"\t\t\t|*******************************|\n"
	);
	printf("\n\t请输入您的选择（1 or 2）：");
}


void operate_interface(){
	printf("\n\n\n\n\n"
	"\t\t\t|****************************|\n"
	"\t\t\t|*    1、判断栈是否为空     *|\n"
	"\t\t\t|*    2、得到栈顶元素       *|\n"
	"\t\t\t|*    3、清空栈             *|\n"
	"\t\t\t|*    4、销毁栈             *|\n"
	"\t\t\t|*    5、检查栈长度         *|\n"
	"\t\t\t|*    6、入栈               *|\n"
	"\t\t\t|*    7、出栈               *|\n"
	"\t\t\t|****************************|\n"
	);
	printf("\n\t请输入您的选择（1-8）：");
}


Status input_data(SqStack *s)
{
	ElemType data;
	int sizes;
	printf("请输入您要创建栈的大小：");
	while(save_get(&sizes) != 1 || sizes == 0){
		printf("请规范输入您要创建栈的大小：");
	}
	if (initStack(s,sizes)){
		printf("初始化栈成功！\n");
	}else{
		printf("初始化栈失败！\n");
		return ERROR;
	}
	printf("请输入您要储存的数据（按q退出）：");
	while (1){
		while (save_get(&data) != SUCCESS)
			goto next;
		pushStack(s, data);
		if (s->top == sizes-1)
			goto next;
		printf("请再输入您要储存数据（按q退出）：");
	}
	next:
	system("cls");
	return SUCCESS;
}

void next_operate(SqStack *s)
{
	ElemType e,data;
	int choice,length;
	interface:
	operate_interface();
	while (1){
		while (save_get(&choice) != SUCCESS ){
			printf("\t请规范您的输入（1-8）：");
		}
		switch (choice){
			case 1:
				if (isEmptyStack(s))
					printf("栈不为空\n");
				else
					printf("栈为空\n");
				system("pause");
				break;
			case 2:
				if(getTopStack(s, &e))
					printf("栈顶元素为%d\n",e);
				else
					printf("没有栈顶元素\n");
				system("pause");
				break;
			case 3:
				clearStack(s);
				printf("清理成功\n");
				system("pause");
				break;
			case 4:
				destroyStack(s);
				printf("销毁成功\n");
				printf("您已退出程序，再见\n");
				system("pause");
				exit(0);
				break;
			case 5:
				stackLength(s, &length);
				printf("栈的长度为%d\n",length);
				system("pause");
				break;
			case 6:
				printf("\t请输入您要入栈的数据：");
				while (save_get(&data) != SUCCESS);
				if(pushStack(s, data))
					printf("入栈成功\n");
				else
					printf("入栈失败，栈已满\n");
				system("pause");
				break;
			case 7:
				if (popStack(s, &data))
					printf("出栈的数据为%d\n",data);
				else
					printf("栈已空\n");
				system("pause");
				break;
			default:
				printf("\t请规范您的输入（1-8）：");
				continue;
		}
		break;
	}
	system("cls");
	goto interface;
}



