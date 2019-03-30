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
			printf("输入有误，请再输入您的选择（1 or 2）：");
		switch (choice){
		case 1:
			system("cls");
			LinkStack s;
			input_data(&s);
			next_operate(&s);
			getchar();
			exit(0);
		case 2:
			printf("\n\n\t程序已退出，再见！\n");
			system("pause");
			exit(0);
		default:		/*无效输入*/
			printf("输入有误，请再输入您的选择（1 or 2）：");
			continue;
		}
	}
	return 0;
}
