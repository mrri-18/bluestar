#include<stdio.h>
int main()
{
	int x, y, z, sum;
	float avg;
	sum = 0;
	printf("세 정수를 입력하시오.: ");      /*정수 세개를 한 번에 입력 받은 후 평균값을 구할 수 있다.*/
	scanf_s("%d%d%d", &x, &y, &z);
	sum = x + y + z;
	avg = sum / 3.0;
	printf("세 수의 평균은 %f 입니다.", avg);
	
	return 0;
}