// 권종 입력 받기,주민등록번호,주문 개수,우대사항

#include <stdio.h>
int main()
{
	int dayOrNight,frontId,year,month,day,realAge,age,todayYear,todayMonth,todayDate,ea,discount,reset;
	float price,result;int totalPrice; int realTotalPrice;
	int ageCase;
	//배열 저장용 
	int count=0;
	int ticketTime[20]={0};
	int discountArr[20]={0};
	int ageCaseArr[20]={0};
	int ticketPriceArr[20]={0};
	int ticketCountArr[20]={0};
	const int BABY_PRICE = 0,ADULT_DAY_PRICE = 56000,ADULT_NIGHT_PRICE = 46000,TEEN_DAY_PRICE = 47000, TEEN_NIGHT_PRICE = 40000,CHILD_DAY_PRICE = 44000, CHILD_NIGHT_PRICE = 37000,OLD_DAY_PRICE = 44000, OLD_NIGHT_PRICE = 37000;
// 나이에 따른 범위
	const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19,
		 MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;
	const int BABY = 1, CHILD = 2, TEEN = 3, ADULT = 4, OLD = 5;	 
// 할인율
	const float DISABLE_DISCOUNT_RATE = 0.6, MERIT_DISCOUNT_RATE = 0.5,
			MULTICHILD_DISCOUNT_RATE = 0.8,PREGNANT_DISCOUNT_RATE = 0.85;

    todayYear = 2022;
	todayMonth = 3;
	todayDate = 24;
	
	//주간권 야간권 선택하기.
	
	do{
	
	printf("아래 중에 선택하세요.\n1. 주간권\n2. 야간권\n");
	scanf("%d",&dayOrNight); 
	printf("주민등록번호 앞 6자리를 입력하세요.\n");
	scanf("%d",&frontId);
	// 나이 계산하기 
	printf("주민번호앞자리:%d\n",frontId);
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
	printf("만나이출력:%d\n",realAge);
	printf("몇 장을 구매하시겠습니까?\n");
	scanf("%d",&ea);
	printf("우대사항을 입력하세요.\n1. 없음(나이는 자동 우대처리) \n2. 장애인\n3. 국가유공자\n4. 다자녀\n5. 임산부\n");
	scanf("%d",&discount);

	// 나이와 선택 시간에 따른 가격 정하기 
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
			printf("잘못누르셨습니다.");
		}
	}
	//우대사항 적용하기
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
	printf("가격은 : %d원 입니다.\n",totalPrice);	
	printf("감사합니다.\n"); 
	//티켓 정보 저장 
	ticketTime[count] = dayOrNight;
	dicountArr[count] = discount;
	ageCaseArr[count] = ageCase;
	ticketPriceArr[count] = price;
	ticketCountArr[count] = ea;
	realTotalPrice +=totalPrice;
	count++;
	printf("계속 발권 하시겠습니까?\n1. 티켓 발권\n2. 종료.");
	scanf("%d",&reset);
	dayOrNight=0;discount=0;ageCase=0;price=0;ea=0;totalPrice=0;
	}while(reset==1);
	return 0;
}
 
