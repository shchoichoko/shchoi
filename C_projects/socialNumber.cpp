//������ ����ϱ�. ���̴� xx�� �� ���̴� xx���Դϴ�.

#include <stdio.h>
int main()
{
	int fullYear;	//�ֹι�ȣ���ڸ� 
	int frontYear; // �⵵ 
	int month; //���� 
	int day;
	printf("�ֹι�ȣ ���ڸ� �Է�: ");
	scanf("%d",&fullYear); 
 	int temp; 	//�� ����� ���� ���� 
	int temp2;	//�� ����� ���� ����
	int realage; 
	int age;
		
	//2000 �����̸� �� �Ʒ������� 
	temp = fullYear+1000000;
	 
	if(1000101<=temp&&temp<=1220315)
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
	age = 2022-frontYear+1;
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
	printf("���� : %d\n",age);
	return 0;
	
}
