// calculate_with_While

#include <stdio.h>
int main()
{
	
	while(true)
	{
		int num1,num2;
		char oper;
		int result;
		printf("값을 입력하시오:");
		scanf("%d %c %d",&num1,&oper,&num2);

		switch(oper)
		{
			case '+':
				result = num1+num2;
				break;
			case '-':
				result = num1-num2;
				break;
			case '*':
				result = num1 * num2;
				break;
			case '/':
				result = num1 / num2;
				break;
			default : 
				printf("잘못입력하셨습니다.\n");
				break;
		}
		printf("결과는: \n");
		printf("%d %c %d = %d\n",num1,oper,num2,result);	
		if(((num1==0)&&num2==0)&&oper=='+')
		{
			break;
		}
	}
return 0;
}
