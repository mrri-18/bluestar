#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int* ptr;  //포인터 선언
	ptr = &a;  //a의 주소를 추출한다.
	cout << "변수 a의 주소는 : " << ptr << endl;
	cout << "a의 값은 : " << *ptr << endl; //포인터 변수로 a에 저장된 값을 알 수 있다.

}
