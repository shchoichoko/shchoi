//��������. ���Ⱑ 5�� �����ϵ��� �ϱ�.

#include <stdio.h>

int main()
{
	int num1,num2;
	char oper;
	int sum,minus,multiple,div;
	printf("������ �Է��ϼ��� :");
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
					printf("%d %c %d = %d �Դϴ�.\n",num1,oper,num2,sum);
				break;
			}
		
		case '-':
			{
					printf("%d %c %d = %d �Դϴ�.\n",num1,oper,num2,minus);
				break;
			}
		case '*' :
			{
					printf("%d %c %d = %d �Դϴ�.\n",num1,oper,num2,multiple);
				break;
			}
		case '/':
			{
				printf("%d %c %d = %d �Դϴ�.\n",num1,oper,num2,div);
				break;
			}
		case '^':
			{
				for(int i=0;i<num2;i++)
				{
					square=square*num1;
				}
					printf("%d %c %d = %d �Դϴ�.\n",num1,oper,num2,square);			
				break;
			}		
		default :
			{
				printf("�߸��Է��ϼ̽��ϴ�.");
				break;
			}
	}
	return 0;	
 } 
