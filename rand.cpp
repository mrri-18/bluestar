#include<iostream>
#include<cstdlib>    //c표준 유틸리티함수를 모은 헤더파일(ex.난수 생성/정수 연산/검색 및 정렬 함수 등을 모음)
#include<ctime>    //time이 가리키는 시간, 초단위 시간을 문자열로 변환하는 
using namespace std;

class random {
public:
	random();    //생성자
	int next();
	int nextInrange(int x, int y);
	
};

random::random() {
	srand((unsigned)time(0));   //시작할 때마다 랜덤한 정수를 발생
}
int random::next() {
	int number;
	while (1) {
		number = rand();
		if (number % 2 == 0) break;
	}
	return number;
}//랜덤한 짝수 정수를 반환하는 함수

int random::nextInrange(int x, int y) {
		int number;
		while (1) {
			number = rand() % (y - x + 1) + x;
			if (number % 2 != 0) break;
		}
		return number;
}
            //범위를 지정해 홀수 정수를 반환하는 함수 
int main() {
	random r;
	int list[10];
	cout << "-- 0에서 " << 32767 << "까지의 짝수 랜덤 정수 10 개--" << endl;  //열번 함수를 호출해서 랜덤 정수 출력
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "== 2에서 " << "30 까지의 홀수 랜덤 정수 10 개 --(단, 중복되는 값이 없어야 함)" << endl;
	for (int i = 0; i < 10; i++) {
	again:; 
		int n = r.nextInrange(2,30);
		for (int j = 0; j < 9; j++)
			if (n == list[j])
				goto again;      //중복되는 값이 있다면 다시 돌아감
		list[i] = n;		
	}
	for(int i=0;i<10;i++)         //배열에 저장된 랜덤 홀수 출력 
		cout << list[i] << ' ';		
	cout << endl;
}