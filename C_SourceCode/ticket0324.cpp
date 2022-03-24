// 권종 입력 받기,주민등록번호,주문 개수,우대사항
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
	
	//주간권 야간권 선택하기.
	printf("아래 중에 선택하세요.\n1. 주간권\n2. 야간권\n");
	scanf("%d",&dayOrNight); 
	printf("주민등록번호를 입력하세요.(숫자만 입력하세요)\n");
	scanf("%d",&fullId);
	// 861213-1009316; 나이 계산하기 
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
	
	printf("만나이출력:%d\n",realAge);
	
	return 0;
}
 
