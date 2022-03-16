//구구단 전체 출력 버젼 

#include <stdio.h>
int main()
{
	int result;
	int num;
	
/*	printf("몇 단을 보시겠습니까? : ");
	scanf("%d",&num);
	printf("\n");
	*/
	 
	for(int index=2;index<10;index++)//단 
	{
		printf("====%d단====\n\n",index); 
		for(num=1;num<10;num++)
		{
			
		result = num * index;
		printf("%d * %d = %d\n",index,num,result);
		
		}
		printf("\n\n\n");
	}
	
	
}
