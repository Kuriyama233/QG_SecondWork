#include <stdio.h>
#include <stdlib.h>
#include "../head/LinkStack.h"
#include "../head/linkstack_funtion.h"

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


Status input_data(LinkStack *s)
{
	ElemType data;
	if (initLStack(s)){
		printf("初始化栈成功！\n");
	}else{
		printf("初始化栈失败！\n");
		return ERROR;
	}
	printf("请输入您要储存的数据（按q退出）：");
	while (1){
		while (save_get(&data) != SUCCESS)
			goto next;
		pushLStack(s, data);
		printf("请再输入您要储存数据（按q退出）：");
	}
	next:
	system("cls");
	return SUCCESS;
}

void next_operate(LinkStack *s)
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
				if (isEmptyLStack(s))
					printf("栈不为空\n");
				else
					printf("栈为空\n");
				system("pause");
				break;
			case 2:
				if(getTopLStack(s, &e))
					printf("栈顶元素为%d\n",e);
				else
					printf("没有栈顶元素\n");
				system("pause");
				break;
			case 3:
				clearLStack(s);
				printf("清理成功\n");
				system("pause");
				break;
			case 4:
				destroyLStack(s);
				printf("销毁成功\n");
				printf("您已退出程序，再见\n");
				system("pause");
				exit(0);
			case 5:
				LStackLength(s, &length);
				printf("栈的长度为%d\n",length);
				system("pause");
				break;
			case 6:
				printf("\t请输入您要入栈的数据：");
				while (save_get(&data) != SUCCESS);
				if(pushLStack(s, data))
					printf("入栈成功\n");
				else
					printf("入栈失败，栈已满\n");
				system("pause");
				break;
			case 7:
				if (popLStack(s, &data))
					printf("出栈的数据为%d\n",data);
				else
					printf("栈已空\n");
				system("pause");
				break;
			default:
				printf("\t请规范您的输入+++（1-8）：");
				continue;
		}
		break;
	}
	system("cls");
	goto interface;
}
