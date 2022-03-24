// 더하기 빼기 곱하기나누기 제곱  기능별로 함수 사용
#include <stdio.h>

int sum(int a, int b)
{
	int result;
	result = a*b;
	return result;
}
int minus(int a, int b)
{
	int result;
	result = a-b;
	return result;
}
int mul(int a,  int b)
{
	int result;
	result = a*b;
	return result;
} 
int devi(int a, int b)
{
	int result;
	result = a/b;
	return result;
} 
int squ(int a, int b)
{
 	int result =1;
 	for(int index=0;index<b;index++)
 	{
 		result = result*a;	
	}
 	return result;
}
int main()
{
 	int returnData;
 	returnData = squ(5,3);
 	printf("%d",returnData);
 	return 0;	
}
