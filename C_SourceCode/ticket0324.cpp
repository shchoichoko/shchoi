// ���� �Է� �ޱ�,�ֹε�Ϲ�ȣ,�ֹ� ����,������
#include <time.h>
#include <stdio.h>
int main()
{
	int dayOrNight;int fullId;int frontId;int year,month,realAge;age;
	time_t timer;
    struct tm* t;
    timer = time(NULL);
    todayYear = t->tm_year + 1900;
	todayMonth = t->tm_mon + 1;
	todayDate = t->tm_mday;
	
	//�ְ��� �߰��� �����ϱ�.
	printf("�Ʒ� �߿� �����ϼ���.\n1. �ְ���\n2. �߰���\n");
	scanf("%d",&dayOrNight); 
	printf("�ֹε�Ϲ�ȣ�� �Է��ϼ���.(���ڸ� �Է��ϼ���)\n");
	scanf("%d",&fullId);
	// 861213-1009316; ���� ����ϱ� 
	frontId = fullId/10000000;
	//861213
	year = frontId/10000;
	month = frontID%10000;
	age = todayYear%100-year+1;
	if(age<=0)
	{
		age +=100;
	}
	if(month<=(todayMonth*100+todayDate))
	{
		realAge = age -1;
	}
	else{
		realAge = age - 2;
	}
	
	printf("���������:%d\n",realAge);
	
	return 0;
}
 
