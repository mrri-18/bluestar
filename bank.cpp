#include<iostream>
using namespace std;

void total(int money, int* b) {   //포인터와 변수를 매개변수로 전달
	for (int i = 0; i < 4; i++)
		money = *(b + i) + money;
	cout << "현재 SWING 자산관리 서비스에 등록된 회원님의 총 자산은 " << money << "원 입니다." << endl;    //총 합산 출력
	cout << "=======================================================================" << endl;

}

void myaccounts(string* a, int* b) {
	std::cout << "*************************SWING 자산관리 서비스*************************" << endl;
	std::cout << "=========================은행 별 계좌정보==============================" << endl;
	for (int i = 0; i < 4; i++)       //은행 이름을 포인터로 받아와 출력
		std::cout << *(a + i);
	cout << "| ";
	std::cout << " " << endl;
	for (int k = 0; k < 4; k++) {           // 잔액을 포인터로 받아와 출력
		if (*(b + k) == 0) {            // 잔액이 0원이라면 계좌없음으로 출력
			cout << "계좌없음 |";
			continue;
		}
		std::cout << *(b + k);
		cout << "| ";
	}
	cout << " " << endl;
	cout << "=======================================================================" << endl;
}

int main() {
	string bank_name[4] = { "하나 |","우리 |","신한  |","국민 |" };        //배열정의
	int bank[4] = { 5000,4000,0,10 };
	int total_money = 0;
	string* p;
	int* q;//이름과 금액에 대한 포인터 선언 
	p = &bank_name[0];
	q = &bank[0];
	myaccounts(p, q);              //은행이름, 금액 배열 출력
	total(total_money, q);       //총 금액 출력 
}
