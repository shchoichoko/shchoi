// ���� �Է� �ޱ�,�ֹε�Ϲ�ȣ,�ֹ� ����,������

#include <stdio.h>
int main()
{
	int dayOrNight,frontId,year,month,day,realAge,age,todayYear,todayMonth,todayDate,ea,discount,reset;
	float price,result;int totalPrice; int realTotalPrice;
	int ageCase;
	//�迭 ����� 
	int count=0;
	int ticketTime[20]={0};
	int discountArr[20]={0};
	int ageCaseArr[20]={0};
	int ticketPriceArr[20]={0};
	int ticketCountArr[20]={0};
	const int BABY_PRICE = 0,ADULT_DAY_PRICE = 56000,ADULT_NIGHT_PRICE = 46000,TEEN_DAY_PRICE = 47000, TEEN_NIGHT_PRICE = 40000,CHILD_DAY_PRICE = 44000, CHILD_NIGHT_PRICE = 37000,OLD_DAY_PRICE = 44000, OLD_NIGHT_PRICE = 37000;
// ���̿� ���� ����
	const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19,
		 MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;
	const int BABY = 1, CHILD = 2, TEEN = 3, ADULT = 4, OLD = 5;	 
// ������
	const float DISABLE_DISCOUNT_RATE = 0.6, MERIT_DISCOUNT_RATE = 0.5,
			MULTICHILD_DISCOUNT_RATE = 0.8,PREGNANT_DISCOUNT_RATE = 0.85;

    todayYear = 2022;
	todayMonth = 3;
	todayDate = 24;
	
	//�ְ��� �߰��� �����ϱ�.
	
	do{
	
	printf("�Ʒ� �߿� �����ϼ���.\n1. �ְ���\n2. �߰���\n");
	scanf("%d",&dayOrNight); 
	printf("�ֹε�Ϲ�ȣ �� 6�ڸ��� �Է��ϼ���.\n");
	scanf("%d",&frontId);
	// ���� ����ϱ� 
	printf("�ֹι�ȣ���ڸ�:%d\n",frontId);
	year = frontId/10000;	
	month = frontId%10000;	
	day = month%100;
	month = month/100;
	if(year<23)
	{	year = year +2000;	}
	else
	{	year = year + 1900;	}
	realAge = todayYear-year;
	if(month<todayMonth)
	{
		realAge = realAge+1;
	} 
	else if(month==todayMonth)
	{
		if(day<=todayDate)
		{	realAge = realAge+1;}
		else
		{	realAge = realAge-1;}
	}
	else if(month>3)
	{
		realAge = realAge-1;
	}
	printf("���������:%d\n",realAge);
	printf("�� ���� �����Ͻðڽ��ϱ�?\n");
	scanf("%d",&ea);
	printf("�������� �Է��ϼ���.\n1. ����(���̴� �ڵ� ���ó��) \n2. �����\n3. ����������\n4. ���ڳ�\n5. �ӻ��\n");
	scanf("%d",&discount);

	// ���̿� ���� �ð��� ���� ���� ���ϱ� 
	switch(dayOrNight)
	{
		case 1:
		{
			if(realAge<=MIN_CHILD)
			{
				price = BABY_PRICE;
				ageCase=BABY;
			}
			else if(MIN_CHILD<realAge&&realAge<=MAX_CHILD)
			{
				price = CHILD_DAY_PRICE;
				ageCase=CHILD
			}
			else if(MIN_TEEN<=realAge&&realAge<=MAX_TEEN)
			{
				price = TEEN_DAY_PRICE;
				ageCase=TEEN;		
			}
			else if(MIN_ADULT<=realAge&&realAge<=MAX_ADULT)
			{
				price = ADULT_DAY_PRICE;
				ageCase=ADULT;
			}
			else if(realAge>MAX_ADULT)
			{
				price = OLD_DAY_PRICE;	
				ageCase=OLD;
			}
			break;
		}
		case 2:
		{
			if(realAge<=MIN_CHILD)
			{
				price = BABY_PRICE;
				ageCase=BABY;
			}
			else if(MIN_CHILD<realAge&&realAge<=MAX_CHILD)
			{
				price = CHILD_NIGHT_PRICE;
				ageCase=CHILD;
			}
			else if(MIN_TEEN<=realAge&&realAge<=MAX_TEEN)
			{
				price = TEEN_NIGHT_PRICE;		
				ageCase=TEEN;
			}
			else if(MIN_ADULT<=realAge&&realAge<=MAX_ADULT)
			{
				price = ADULT_NIGHT_PRICE;
				ageCase=ADULT;
			}
			else if(realAge>MAX_ADULT)
			{
				price = OLD_NIGHT_PRICE;	
				ageCase=OLD;
			}
			break;
		}
		default :
		{
			printf("�߸������̽��ϴ�.");
		}
	}
	//������ �����ϱ�
	if(discount ==1)
	{	
		result = price;
	}
	else if(discount ==2)
	{
		result = price*DISABLE_DISCOUNT_RATE;
	}
	else if(discount ==3)
	 {
	 	result = price*MERIT_DISCOUNT_RATE;
	 }
	else if(discount ==4)
	{
		result = price*MULTICHILD_DISCOUNT_RATE;
	}
	else if(discount ==5)
	{
		result = price*PREGNANT_DISCOUNT_RATE;
	}
	totalPrice = result*ea;
	printf("������ : %d�� �Դϴ�.\n",totalPrice);	
	printf("�����մϴ�.\n"); 
	//Ƽ�� ���� ���� 
	ticketTime[count] = dayOrNight;
	dicountArr[count] = discount;
	ageCaseArr[count] = ageCase;
	ticketPriceArr[count] = price;
	ticketCountArr[count] = ea;
	realTotalPrice +=totalPrice;
	count++;
	printf("��� �߱� �Ͻðڽ��ϱ�?\n1. Ƽ�� �߱�\n2. ����.");
	scanf("%d",&reset);
	dayOrNight=0;discount=0;ageCase=0;price=0;ea=0;totalPrice=0;
	}while(reset==1);
	return 0;
}
 
