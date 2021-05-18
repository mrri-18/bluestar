#include<iostream>
using namespace std;

#include "Class.h"

oval::oval() {

}
oval::oval(int x, int y) {           // 높이와 너비를 설정
	A = x;
	B = y;

}
int oval::getA() {     //A값을 리턴
	return A;
}
int oval::getB() {
	return B;

}void oval::Area() {        //타원의 넓이를 구하는 함수 
	double result;
	result = (A / 2) * (B / 2) * (3.14);
	cout << "타원의 넓이는 " << result << "이다." << endl;
}
void oval::set(int x, int y) {         //높이, 너비를 설정
	A = x;
	B = y;

}
oval:: ~oval() {
	cout << "Oval 소멸: width = " << getA() << ", height = " << getB() << endl;
}
