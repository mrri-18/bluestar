#include <iostream> 
#include<string>
using namespace std;
int main(){
	int cnt, cas;string str;
	cin >> cas;
	for (int k = 0; k < cas; k++) {  //cas에 입력된 수 만큼 문자열 입력 받기
		cin >> cnt >> str;
		for (int i = 0; i < str.length(); i++) { //length()함수를 몰라서 글짜 최대 수로 범위를 잡았다 고침
			for (int j = 0; j < cnt; j++) {  //cnt횟수만큼 각 문자들을 반복 
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0; }
