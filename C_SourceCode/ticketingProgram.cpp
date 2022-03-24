//롯데월드 티켓팅 프로그램

#include <stdio.h>
int main()
{
	int fullYear;	//주민번호앞자리 
	int frontYear; // 년도 
	int month; //월일 
	int day;
 	int temp; 	//년 계산을 위한 변수 
	int temp2;	//월 계산을 위한 변수
	int realage; // 만나이 
	int restart=0;	//반복문을 위한 변수 
	int multiTicket;	// 이용권 구분을 위한 변수 
	int dayTicket;	//주간권 야간권 구분을 위한 변수 
	int restart2=0;	//주간권 야간권 선택시 되돌리기 위함. 
	int howMany = 0;	//티켓 구매 원하는 수량표기를 위한 변수.
	int special;	//우대사항 선택을 위한 변수. 
	float price;	//기본 가격 
	float result;	//할인 계산결과 
	int totalPrice;	//최종 가격 
	int keepgo;
	int reorder;	//주문 갯수 1~10장까지만 입력 가능. 
	
	const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19,
		 MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;

	const int MULTI_REAL_BABY_PRICE = 0,MULTI_BABY_PRICE = 15000,
		 MULTI_ADULT_DAY_PRICE = 59000, MULTI_ADULT_NIGHT_PRICE = 48000,
		 MULTI_TEEN_DAY_PRICE = 52000, MULTI_TEEN_NIGHT_PRICE = 42000,
		 MULTI_CHILD_DAY_PRICE = 47000, MULTI_CHILD_NIGHT_PRICE = 36000;
	
	const int PARK_REAL_BABY_PRICE = 0,PARK_BABY_PRICE = 15000,
		 PARK_ADULT_DAY_PRICE = 56000, PARK_ADULT_NIGHT_PRICE = 45000,
		 PARK_TEEN_DAY_PRICE = 50000, PARK_TEEN_NIGHT_PRICE = 40000,
		 PARK_CHILD_DAY_PRICE = 46000, PARK_CHILD_NIGHT_PRICE = 35000;
		 		 
	const float DISABLE_DISCOUNT_RATE = 0.6, MERIT_DISCOUNT_RATE = 0.5,
			MULTI_CHILD_DISCOUNT_RATE = 0.8,	PREGNANT_DISCOUNT_RATE = 0.85;
	
	
	
	while(restart==0)						//전체 반복문을 위해 Whild문으로 덮음. 
	{
			
			printf("이용권을 선택하세요.\n");
			printf("1. 종합이용권.\n");	
			printf("2. 파크이용권.\n");	
			printf("3. 티켓 구매 원치 않음.\n");
			printf("=========================\n");
			scanf("%d",&multiTicket);	
			
		
		switch(multiTicket)
		{
			case 1:	//종합이용권 선택시 
			{
				while(restart2=0)
				printf("티켓 종류를 선택하세요.\n");
				printf("1. 주간권.\n");	
				printf("2. 야간권.\n");	
				printf("3. 티켓 구매 원치 않음.\n");
				printf("=========================\n");
				scanf("%d",&dayTicket);
				switch(dayTicket)
				{
					case 1:	//주간이용권 선택시 
					{
						printf("주간이용권을 고르셨습니다.\n");
						printf("주민등록번호 앞자리를 입력하세요.\n");
						printf("예시:950505\n");
						scanf("%d",&fullYear); 	
						//2000 년대생이면 이 아래식으로 
						temp = fullYear+1000000;
	 
						if(1000101<=temp&&temp<=1220316)
						{
							frontYear = (fullYear+20000000)/10000;

							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						//1900 년대생 년도 구하기 
						else
						{
							frontYear = (fullYear+19000000)/10000;

							// 달,날짜 구하기
							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						// 만나이 계산하기. 현재년도 - 생년. 생일 안지나면 -1  그냥 나이 : 뺀거 더하기 1 
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
						// 나이에 따라 가격 정하기 
						if(realage<=MAX_ADULT&&realage>=MIN_ADULT)		//성인 
						{price = MULTI_ADULT_DAY_PRICE;}
						else if(realage>MAX_ADULT)						//노인  
						{price = MULTI_CHILD_DAY_PRICE;}
						else if(realage>=MIN_TEEN&&realage<=MAX_TEEN)	//십대 
						{price = MULTI_TEEN_DAY_PRICE;}
						else if(realage>=MIN_CHILD&&realage<=MAX_CHILD)	//어린이
						{price = MULTI_CHILD_DAY_PRICE;} 
						else if(realage>=MIN_BABY&&realage<MIN_CHILD)	//영유아
						{price = MULTI_REAL_BABY_PRICE;} 
						printf("몇 개를 주문하시겠습니까?(최대 10개)\n");
						scanf("%d",&howMany);
						printf("우대사항을 선택하세요.\n");
						printf("1.없음(나이 우대는 자동처리됩니다.)\n");
						printf("2.장애인\n");
						printf("3.국가유공자\n");
						printf("4.다자녀\n");
						printf("5.임산부\n");
						scanf("%d",&special);
						if(special==1)
						{
							result = price * 1;
						}
						else if(special==2)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;	
							}
							else{	result = price * DISABLE_DISCOUNT_RATE;	}
						}
						else if(special==3)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MERIT_DISCOUNT_RATE;	}
						}
						else if(special==4)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MULTI_CHILD_DISCOUNT_RATE;	}
						}
						else if(special==5)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * PREGNANT_DISCOUNT_RATE;	}
						}
						totalPrice = result * howMany;
						printf("가격은 %d원입니다.\n",totalPrice);	
						printf("감사합니다!\n");
						printf("계속 발권하시겠습니까?\n");
						printf("1.티켓  발권\n");
						printf("2.종 료\n");
						scanf("%d",&keepgo);
						if(keepgo==1)
						{
							restart=0;
						} 
						else if(keepgo==2)
						{
							restart=1;
						}
						restart2=1;
						break;
					}
					
					case 2:	//야간이용권 선택시 
					{
						printf("야간이용권을 고르셨습니다.\n");
						printf("주민등록번호 앞자리를 입력하세요.\n");
						printf("예시:950505\n");
						scanf("%d",&fullYear); 	
						temp = fullYear+1000000;
	 
						if(1000101<=temp&&temp<=1220316)
						{
							frontYear = (fullYear+20000000)/10000;

							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						} 
						else
						{
							frontYear = (fullYear+19000000)/10000;
							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
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
						// 나이에 따라 가격 정하기 
						if(realage<=MAX_ADULT&&realage>=MIN_ADULT)		//성인 
						{price = MULTI_ADULT_NIGHT_PRICE;}
						else if(realage>MAX_ADULT)						//노인  
						{price = MULTI_CHILD_NIGHT_PRICE;}
						else if(realage>=MIN_TEEN&&realage<=MAX_TEEN)	//십대 
						{price = MULTI_TEEN_NIGHT_PRICE;}
						else if(realage>=MIN_CHILD&&realage<=MAX_CHILD)	//어린이
						{price = MULTI_CHILD_NIGHT_PRICE;} 
						else if(realage>=MIN_BABY&&realage<MIN_CHILD)	//영유아
						{price = MULTI_REAL_BABY_PRICE;}  				
						printf("몇 개를 주문하시겠습니까?(최대 10개)\n");
						scanf("%d",&howMany);
						printf("우대사항을 선택하세요.\n");
						printf("1.없음(나이 우대는 자동처리됩니다.)\n");
						printf("2.장애인\n");
						printf("3.국가유공자\n");
						printf("4.다자녀\n");
						printf("5.임산부\n");
						scanf("%d",&special);
						if(special==1)
						{
							result = price * 1;
						}
						else if(special==2)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;	
							}
							else{	result = price * DISABLE_DISCOUNT_RATE;	}
						}
						else if(special==3)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MERIT_DISCOUNT_RATE;	}
						}
						else if(special==4)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MULTI_CHILD_DISCOUNT_RATE;	}
						}
						else if(special==5)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * PREGNANT_DISCOUNT_RATE;	}
						}
						totalPrice = result * howMany;
						printf("가격은 %d원입니다.\n",totalPrice);		
						printf("감사합니다!\n");				
						restart2=1;
						break;
					}
					
					case 3:	//티겟 구매를 원하지 않을시
					{
						restart2=1;
						restart=1;
						break;
					}
					
					default :	//잘못 눌렀을 시
					{
						printf("잘못입력하셨습니다.처음으로 돌아갑니다.\n");
						restart2=0;
						break; 
					} 
				}
				break;
			}
			
			case 2:	//파크이용권 선택시 
			{			
				while(restart2=0)
				printf("티켓 종류를 선택하세요.\n");
				printf("1. 주간권.\n");	
				printf("2. 야간권.\n");	
				printf("3. 티켓 구매 원치 않음.\n");
				printf("=========================\n");
				scanf("%d",&dayTicket);
				switch(dayTicket)
				{
					case 1:	//주간이용권 선택시 
					{
						printf("주간이용권을 고르셨습니다.\n");
						printf("주민등록번호 앞자리를 입력하세요.\n");
						printf("예시:950505\n");
						scanf("%d",&fullYear); 	
						//2000 년대생이면 이 아래식으로 
						temp = fullYear+1000000;
	 
						if(1000101<=temp&&temp<=1220316)
						{
							frontYear = (fullYear+20000000)/10000;

							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						//1900 년대생 년도 구하기 
						else
						{
							frontYear = (fullYear+19000000)/10000;

							// 달,날짜 구하기
							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						// 만나이 계산하기. 현재년도 - 생년. 생일 안지나면 -1  그냥 나이 : 뺀거 더하기 1 
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
						// 나이에 따라 가격 정하기 
						if(realage<=MAX_ADULT&&realage>=MIN_ADULT)		//성인 
						{price = PARK_ADULT_DAY_PRICE;}
						else if(realage>MAX_ADULT)						//노인  
						{price = PARK_CHILD_DAY_PRICE;}
						else if(realage>=MIN_TEEN&&realage<=MAX_TEEN)	//십대 
						{price = PARK_TEEN_DAY_PRICE;}
						else if(realage>=MIN_CHILD&&realage<=MAX_CHILD)	//어린이
						{price = PARK_CHILD_DAY_PRICE;} 
						else if(realage>=MIN_BABY&&realage<MIN_CHILD)	//영유아
						{price = PARK_REAL_BABY_PRICE;} 
							
						printf("몇 개를 주문하시겠습니까?(최대 10개)\n");
						scanf("%d",&howMany);
						printf("우대사항을 선택하세요.\n");
						printf("1.없음(나이 우대는 자동처리됩니다.)\n");
						printf("2.장애인\n");
						printf("3.국가유공자\n");
						printf("4.다자녀\n");
						printf("5.임산부\n");
						scanf("%d",&special);
						if(special==1)
						{
							result = price * 1;
						}
						else if(special==2)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;	
							}
							else{	result = price * DISABLE_DISCOUNT_RATE;	}
						}
						else if(special==3)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MERIT_DISCOUNT_RATE;	}
						}
						else if(special==4)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MULTI_CHILD_DISCOUNT_RATE;	}
						}
						else if(special==5)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * PREGNANT_DISCOUNT_RATE;	}
						}
						totalPrice = result * howMany;
						printf("가격은 %d원입니다.\n",totalPrice);	
						printf("감사합니다!\n");
						restart2=1;
						break;
					}
						
					
					case 2:	//야간이용권 선택시 
					{
						printf("야간이용권을 고르셨습니다.\n");
						printf("주민등록번호 앞자리를 입력하세요.\n");
						printf("예시:950505\n");
						scanf("%d",&fullYear); 	
						temp = fullYear+1000000;
	 
						if(1000101<=temp&&temp<=1220316)
						{
							frontYear = (fullYear+20000000)/10000;

							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						} 
						else
						{
							frontYear = (fullYear+19000000)/10000;
							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
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
						// 나이에 따라 가격 정하기 
						if(realage<=MAX_ADULT&&realage>=MIN_ADULT)		//성인 
						{price = PARK_ADULT_NIGHT_PRICE;}
						else if(realage>MAX_ADULT)						//노인  
						{price = PARK_CHILD_NIGHT_PRICE;}
						else if(realage>=MIN_TEEN&&realage<=MAX_TEEN)	//십대 
						{price = PARK_TEEN_NIGHT_PRICE;}
						else if(realage>=MIN_CHILD&&realage<=MAX_CHILD)	//어린이
						{price = PARK_CHILD_NIGHT_PRICE;} 
						else if(realage>=MIN_BABY&&realage<MIN_CHILD)	//영유아
						{price = PARK_REAL_BABY_PRICE;}  			
						printf("몇 개를 주문하시겠습니까?(최대 10개)\n");
						scanf("%d",&howMany);	
						printf("우대사항을 선택하세요.\n");
						printf("1.없음(나이 우대는 자동처리됩니다.)\n");
						printf("2.장애인\n");
						printf("3.국가유공자\n");
						printf("4.다자녀\n");
						printf("5.임산부\n");
						scanf("%d",&special);
						if(special==1)
						{
							result = price * 1;
						}
						else if(special==2)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;	
							}
							else{	result = price * DISABLE_DISCOUNT_RATE;	}
						}
						else if(special==3)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MERIT_DISCOUNT_RATE;	}
						}
						else if(special==4)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MULTI_CHILD_DISCOUNT_RATE;	}
						}
						else if(special==5)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * PREGNANT_DISCOUNT_RATE;	}
						}
						totalPrice = result * howMany;
						printf("가격은 %d원입니다.\n",totalPrice);		
						printf("감사합니다!\n");				
						restart2=1;
						break;
					}
					
					case 3:	//티겟 구매를 원하지 않을시
					{
						restart2=1;
						restart=1;
						break;
					}
					
					default :	//잘못 눌렀을 시
					{
						printf("잘못입력하셨습니다.처음으로 돌아갑니다.\n");
						restart2=0;
						break; 
					} 
				}	
				break;
			}
			case 3:
			{	
				restart=1;
				break; 
			}	
			
			default :	//그 외 입력시 
			{
				printf("잘못입력하셨습니다."); 
				break;
			}
			
		}
	}
	
	return 0;
}
