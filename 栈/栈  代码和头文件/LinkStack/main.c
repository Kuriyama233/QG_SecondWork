#include <stdio.h>
#include <stdlib.h>
#include "../head/LinkStack.h"
#include "../head/linkstack_funtion.h"

int main()
{
	ElemType choice;
	initial_interface();
	while (1){
		while (save_get(&choice) != SUCCESS)
			printf("��������������������ѡ��1 or 2����");
		switch (choice){
		case 1:
			system("cls");
			LinkStack s;
			input_data(&s);
			next_operate(&s);
			getchar();
			exit(0);
		case 2:
			printf("\n\n\t�������˳����ټ���\n");
			system("pause");
			exit(0);
		default:		/*��Ч����*/
			printf("��������������������ѡ��1 or 2����");
			continue;
		}
	}
	return 0;
}
