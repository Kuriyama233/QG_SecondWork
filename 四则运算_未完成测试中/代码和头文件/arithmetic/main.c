#include <stdio.h>
#include <stdlib.h>
#include "../head/stack.h"

int main()
{

	LinkStack Sign, Num;
	initLStack(&Sign);
	initLStack(&Num);

	char *str;
	get_string(str,&Num);

	Data data;
	while(Num.count != 0){
		popLStack(&Num, &data);
//		printf("%d",data.judge);getchar();
		if(data.judge)
			printf("%f",data.unit.num);
		else
			printf("%c",data.unit.sign);
	}

	return 0;
}
