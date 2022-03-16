//만나이 계산하기. 나이는 xx세 만 나이는 xx세입니다.

#include <stdio.h>
int main()
{
	int fullYear;	//주민번호앞자리 
	int frontYear; // 년도 
	int month; //월일 
	int day;
	printf("주민번호 앞자리 입력: ");
	scanf("%d",&fullYear); 
 	int temp; 	//년 계산을 위한 변수 
	int temp2;	//월 계산을 위한 변수
	int realage; 
	int age;
		
	//2000 년대생이면 이 아래식으로 
	temp = fullYear+1000000;
	 
	if(1000101<=temp&&temp<=1220315)
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
	
	printf("만 나이 : %d\n",realage);
	printf("나이 : %d\n",age);
	return 0;
	
}
