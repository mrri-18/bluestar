#include<iostream>
using namespace std;

#include "Class.h"

oval::oval() {

}
oval::oval(int x, int y) {           // ���̿� �ʺ� ����
	A = x;
	B = y;

}
int oval::getA() {     //A���� ����
	return A;
}
int oval::getB() {
	return B;

}void oval::Area() {        //Ÿ���� ���̸� ���ϴ� �Լ� 
	double result;
	result = (A / 2) * (B / 2) * (3.14);
	cout << "Ÿ���� ���̴� " << result << "�̴�." << endl;
}
void oval::set(int x, int y) {         //����, �ʺ� ����
	A = x;
	B = y;

}
oval:: ~oval() {
	cout << "Oval �Ҹ�: width = " << getA() << ", height = " << getB() << endl;
}
