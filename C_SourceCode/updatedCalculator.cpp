//연습문제. 계산기가 5번 수행하도록 하기.

#include <stdio.h>

int main()
{
	int num1,num2;
	char oper;
	int sum,minus,multiple,div;
	printf("수식을 입력하세요 :");
	scanf("%d %c %d",&num1,&oper,&num2);
	sum = num1 + num2;
	minus = num1 - num2;
	multiple = num1 * num2;
	div = num1 / num2;
	int square = 1;
	
	switch(oper)
	{
		case '+':
			{
					printf("%d %c %d = %d 입니다.\n",num1,oper,num2,sum);
				break;
			}
		
		case '-':
			{
					printf("%d %c %d = %d 입니다.\n",num1,oper,num2,minus);
				break;
			}
		case '*' :
			{
					printf("%d %c %d = %d 입니다.\n",num1,oper,num2,multiple);
				break;
			}
		case '/':
			{
				printf("%d %c %d = %d 입니다.\n",num1,oper,num2,div);
				break;
			}
		case '^':
			{
				for(int i=0;i<num2;i++)
				{
					square=square*num1;
				}
					printf("%d %c %d = %d 입니다.\n",num1,oper,num2,square);			
				break;
			}		
		default :
			{
				printf("잘못입력하셨습니다.");
				break;
			}
	}
	return 0;	
 } 
