#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int* ptr;  //������ ����
	ptr = &a;  //a�� �ּҸ� �����Ѵ�.
	cout << "���� a�� �ּҴ� : " << ptr << endl;
	cout << "a�� ���� : " << *ptr << endl; //������ ������ a�� ����� ���� �� �� �ִ�.

}
