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
	/*
	printf("주민번호 앞자리 입력: ");
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
	
	printf("만 나이 : %d\n",realage);
	*/
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
				break;
			}
			
			case 2:	//파크이용권 선택시 
			{
				
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
