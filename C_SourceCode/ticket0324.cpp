// 권종 입력 받기,주민등록번호,주문 개수,우대사항
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

	int dayOrNight,frontId,year,month,day,realAge,age,ea,discount,reset;
	float price,result;int totalPrice; int realTotalPrice; int nextCustomer;
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

    int todayYear = 2022;
	int todayMonth = 3;
	int todayDate = 24;
void inputMessage()
{
	printf("아래 중에 선택하세요.\n1. 주간권\n2. 야간권\n");
	scanf("%d",&dayOrNight); 
	printf("주민등록번호 앞 6자리를 입력하세요.\n");
	scanf("%d",&frontId);
	printf("주민번호앞자리:%d\n",frontId);
	printf("몇 장을 구매하시겠습니까?\n");
	scanf("%d",&ea);
	printf("우대사항을 입력하세요.\n1. 없음(나이는 자동 우대처리) \n2. 장애인\n3. 국가유공자\n4. 다자녀\n5. 임산부\n");
	scanf("%d",&discount);
}
void selectAge()		// 만나이 계산하기 
{
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
}

void selectPrice()		// 나이와 선택 시간에 따른 가격 정하기 
{
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
					ageCase=CHILD;
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
}
void doDiscount()		//우대사항 적용하기
{
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
} 
void doReceipt()
{
	FILE *filePointer = fopen("report.csv","a");
		
		// 영수증 출력
		printf("\n\n===================================== %s =====================================\n","에버랜드") ;
		printf("%s\t\t%s\t     %s\t  %s\t\t%s\n\n","선택사항","연  령","매수","가격","우대사항");
		for (int i =0; i<count; i++) {
			//데이터 파일형식으로 저장 
			fprintf(filePointer,"%d,%d,%d,%d,%d,%d,%d,%d\n",
								todayYear,todayMonth,todayDate,
								ticketTime[i],discountArr[i],ageCaseArr[i],ticketCountArr[i],ticketPriceArr[i]);
			switch (ticketTime[i]) {
				case 1:
					printf("\t%s","주간이용권");
					break;
				case 2:
					printf("\t%s","야간이용권");
					break;

				default:
					break;
			}
			
			switch (ageCaseArr[i]) {
				case 1:
					printf("\t%s","유  아");
					break;
				case 2:
					printf("\t%s","어린이");
					break;
				case 3:
					printf("\t%s","학  생");
					break;
				case 4:
					printf("\t%s","성  인");
					break;
				case 5:
					printf("\t%s","노  인");
					break; 
				default:
					break;
			}
			
			printf("%10d%14d원\t",ticketCountArr[i],ticketPriceArr[i]) ;
			
			switch (discountArr[i]) {
				case 1:
					printf("%s\n","우대사항 없음");
					break;
				case 2:
					printf("%s\n","장애인 우대");
					break;
				case 3:
					printf("%s\n","국가유공자 우대");
					break;
				case 4:
					printf("%s\n","다자녀  우대");
					break;
				case 5:
					printf("%s\n","임산부 우대");
					break;
				default:
					break;
			}
		}
		printf("\n입장료 총액은 %d원 입니다.", realTotalPrice);
		printf("\n=====================================================================================\n") ;
		printf("\n새로운 주문을 받겠습니까?\n1.예\n2.종료\n");
		scanf("%d",&nextCustomer);
		count = 0;
		realTotalPrice=0;
}	
void ticketInfo()
{
		ticketTime[count] = dayOrNight;
		discountArr[count] = discount;
		ageCaseArr[count] = ageCase;
		ticketPriceArr[count] = price;
		ticketCountArr[count] = ea;
		realTotalPrice +=totalPrice;
		count++;
		printf("계속 발권 하시겠습니까?\n1. 티켓 발권\n2. 종료.");
		scanf("%d",&reset);
		dayOrNight=0;discount=0;ageCase=0;price=0;ea=0;totalPrice=0;
}
int main()
{
	
	//주간권 야간권 선택하기.
	do{
	
		do{
		inputMessage();			
		selectAge();			// 만나이 계산하기 
		selectPrice();			// 나이와 선택 시간에 따른 가격 정하기
		doDiscount();			// 우대사항 적용하기 
		
		printf("가격은 : %d원 입니다.\n",totalPrice);	
		printf("감사합니다.\n"); 
		//티켓 정보 저장 
		ticketInfo();
		}while(reset==1);
		doReceipt();
	}while(nextCustomer==1);
	return 0;
}



