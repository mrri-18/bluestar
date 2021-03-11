#include<stdio.h>
int main()
{
	int x, y, z, sum;
	float avg;
	sum = 0;
	printf("input three integers.: ");      /*정수 세개를 한 번에 입력 받은 후 평균값을 구할 수 있다.*/
	scanf_s("%d%d%d", &x, &y, &z);
	sum = x + y + z;
	avg = sum / 3.0;
	printf("the average value of three integers is %f.", avg);
	
	return 0;
}
