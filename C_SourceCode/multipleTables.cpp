//������ ��ü ��� ���� 

#include <stdio.h>
int main()
{
	int result;
	int num;
	
/*	printf("�� ���� ���ðڽ��ϱ�? : ");
	scanf("%d",&num);
	printf("\n");
	*/
	 
	for(int index=2;index<10;index++)//�� 
	{
		printf("====%d��====\n\n",index); 
		for(num=1;num<10;num++)
		{
			
		result = num * index;
		printf("%d * %d = %d\n",index,num,result);
		
		}
		printf("\n\n\n");
	}
	
	
}
