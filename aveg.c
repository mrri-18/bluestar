#include<stdio.h>
int main()
{
	int x, y, z, sum;
	float avg;
	sum = 0;
	printf("�� ������ �Է��Ͻÿ�.: ");      /*���� ������ �� ���� �Է� ���� �� ��հ��� ���� �� �ִ�.*/
	scanf_s("%d%d%d", &x, &y, &z);
	sum = x + y + z;
	avg = sum / 3.0;
	printf("�� ���� ����� %f �Դϴ�.", avg);
	
	return 0;
}