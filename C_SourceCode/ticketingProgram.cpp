//�Ե����� Ƽ���� ���α׷�

#include <stdio.h>
int main()
{
	int fullYear;	//�ֹι�ȣ���ڸ� 
	int frontYear; // �⵵ 
	int month; //���� 
	int day;
 	int temp; 	//�� ����� ���� ���� 
	int temp2;	//�� ����� ���� ����
	int realage; // ������ 
	int restart=0;	//�ݺ����� ���� ���� 
	int multiTicket;	// �̿�� ������ ���� ���� 
	/*
	printf("�ֹι�ȣ ���ڸ� �Է�: ");
	scanf("%d",&fullYear); 	
	//2000 �����̸� �� �Ʒ������� 
	temp = fullYear+1000000;
	 
	if(1000101<=temp&&temp<=1220316)
	{
		frontYear = (fullYear+20000000)/10000;

		temp2 = (fullYear/100)*100;
		day = fullYear-temp2;
		temp2 = (fullYear/10000)*10000;
		month = (fullYear - temp2 - day)/100;
	}
	//1900 ���� �⵵ ���ϱ� 
	else
	{
		frontYear = (fullYear+19000000)/10000;

		// ��,��¥ ���ϱ�
		temp2 = (fullYear/100)*100;
		day = fullYear-temp2;
		temp2 = (fullYear/10000)*10000;
		month = (fullYear - temp2 - day)/100;
	}
	// ������ ����ϱ�. ����⵵ - ����. ���� �������� -1  �׳� ���� : ���� ���ϱ� 1 
	realage = 2022-frontYear;
	if(month<3)
	{
		realage = realage+1;
	} 
	else if(month==3)
	{
		if(day<=15)
		{
			realage = realage+1;
		}
		else
		{
			realage = realage-1;
		}
	}
	else if(month>3)
	{
		realage = realage-1;
	}
	
	printf("�� ���� : %d\n",realage);
	*/
	while(restart==0)						//��ü �ݺ����� ���� Whild������ ����. 
	{
			
			printf("�̿���� �����ϼ���.\n");
			printf("1. �����̿��.\n");	
			printf("2. ��ũ�̿��.\n");	
			printf("3. Ƽ�� ���� ��ġ ����.\n");
			printf("=========================\n");
			scanf("%d",&multiTicket);	
			
		
		switch(multiTicket)
		{
			case 1:	//�����̿�� ���ý� 
			{
				break;
			}
			
			case 2:	//��ũ�̿�� ���ý� 
			{
				
				break;
			}
			case 3:
			{	
				restart=1;
				break; 
			}	
			
			default :	//�� �� �Է½� 
			{
				printf("�߸��Է��ϼ̽��ϴ�."); 
				break;
			}
			
		}
	}
	
	return 0;
} 
