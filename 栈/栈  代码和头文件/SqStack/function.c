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
	"\t\t\t|*         ����һ��ջ          *|\n"
	"\t\t\t|*   1����ʼ��һ��ջ           *|\n"
	"\t\t\t|*   2���˳�����               *|\n"
	"\t\t\t|*******************************|\n"
	);
	printf("\n\t����������ѡ��1 or 2����");
}


void operate_interface(){
	printf("\n\n\n\n\n"
	"\t\t\t|****************************|\n"
	"\t\t\t|*    1���ж�ջ�Ƿ�Ϊ��     *|\n"
	"\t\t\t|*    2���õ�ջ��Ԫ��       *|\n"
	"\t\t\t|*    3�����ջ             *|\n"
	"\t\t\t|*    4������ջ             *|\n"
	"\t\t\t|*    5�����ջ����         *|\n"
	"\t\t\t|*    6����ջ               *|\n"
	"\t\t\t|*    7����ջ               *|\n"
	"\t\t\t|****************************|\n"
	);
	printf("\n\t����������ѡ��1-8����");
}


Status input_data(SqStack *s)
{
	ElemType data;
	int sizes;
	printf("��������Ҫ����ջ�Ĵ�С��");
	while(save_get(&sizes) != 1 || sizes == 0){
		printf("��淶������Ҫ����ջ�Ĵ�С��");
	}
	if (initStack(s,sizes)){
		printf("��ʼ��ջ�ɹ���\n");
	}else{
		printf("��ʼ��ջʧ�ܣ�\n");
		return ERROR;
	}
	printf("��������Ҫ��������ݣ���q�˳�����");
	while (1){
		while (save_get(&data) != SUCCESS)
			goto next;
		pushStack(s, data);
		if (s->top == sizes-1)
			goto next;
		printf("����������Ҫ�������ݣ���q�˳�����");
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
			printf("\t��淶�������루1-8����");
		}
		switch (choice){
			case 1:
				if (isEmptyStack(s))
					printf("ջ��Ϊ��\n");
				else
					printf("ջΪ��\n");
				system("pause");
				break;
			case 2:
				if(getTopStack(s, &e))
					printf("ջ��Ԫ��Ϊ%d\n",e);
				else
					printf("û��ջ��Ԫ��\n");
				system("pause");
				break;
			case 3:
				clearStack(s);
				printf("����ɹ�\n");
				system("pause");
				break;
			case 4:
				destroyStack(s);
				printf("���ٳɹ�\n");
				printf("�����˳������ټ�\n");
				system("pause");
				exit(0);
				break;
			case 5:
				stackLength(s, &length);
				printf("ջ�ĳ���Ϊ%d\n",length);
				system("pause");
				break;
			case 6:
				printf("\t��������Ҫ��ջ�����ݣ�");
				while (save_get(&data) != SUCCESS);
				if(pushStack(s, data))
					printf("��ջ�ɹ�\n");
				else
					printf("��ջʧ�ܣ�ջ����\n");
				system("pause");
				break;
			case 7:
				if (popStack(s, &data))
					printf("��ջ������Ϊ%d\n",data);
				else
					printf("ջ�ѿ�\n");
				system("pause");
				break;
			default:
				printf("\t��淶�������루1-8����");
				continue;
		}
		break;
	}
	system("cls");
	goto interface;
}



