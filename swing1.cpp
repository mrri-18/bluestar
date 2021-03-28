
#include <iostream>
using namespace std;
int main()
{
	int f1, f2, f3, s1, s2, s3, sum;
    char name[8];
    cout << "당신의 이름은 무엇입니까? : ";
	cin.getline(name, 8); //공백을 포함한 문자열을 입력받을 수 있다.
	cout << "반갑습니다. " << name << "님\n";
	cout << "apple의 가격은 얼마입니까?  ";		//과일의 각각 가격을 입력받는다.
	cin >> f1;
	cout << "banana의 가격은 얼마입니까? ";
	cin >> f2;
	cout << "orange의 가격은 얼마입니까? ";
	cin >> f3;
	cout << "apple은 몇 개 있습니까? ";            // 과일의 각각 개수를 입력받는다.
	cin >> s1;
	cout << "banana은 몇 개 있습니까? ";
	cin >> s2;
	cout << "orange은 몇 개 있습니까? ";
	cin >> s3;
		
	sum = (s1 * f1 + s2 * f2 + s3 * f3) - 500;         //총 가격과 마지막으로 500원을 할인한다.
	cout << "총" << sum << "원 입니다.\n";            //총금액을 출력한다.
	return 0;
} 