#include<stdio.h>
int main()
{
	int x, y, z, sum;
	float avg;
	sum = 0;
	printf("input three integers.: ");    /*����Ʈ���� ������ �� &�� ����������.*/
	scanf_s("%d%d%d", &x, &y, &z);
	sum = x + y + z;
	avg = sum / 3.0;
	printf("the average of three integers is %f.", avg);

	return 0;
}