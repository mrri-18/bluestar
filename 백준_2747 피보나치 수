#include <iostream> 
using namespace std;
int main(){
	int n=2,cnt,num1=0, num2=1,cmt;   //0번째, 1번째 수는 주어진 상태
	cin >> cnt;  //(cnt)번째 피보나치 수를 구하기 위해 범위를 정함.
	if (cnt == 0)cout << 0 << endl;  
	if (cnt == 1)cout << 1 << endl;
	if (cnt >= 2) {     //범위가 2보다 클 때, while문을 통해 피보나치 수들을 계산한다.
		while (n <= cnt) {
			cmt = num1 + num2;   //앞의 두 수의 합은 cmt라는 변수에 저장.
			num1 = num2;         // 두개의 숫자 중 큰 수는 num1에 저장되고 합은 다시 num2에 저장
			num2 = cmt;          //숫자들을 서로 교환하면서 다음에 올 피보나치 수를 계산
			n++;
		}
		cout << num2 << endl;    //해당범위보다 n값이 커지면 while문에서 나와 마지막으로 합한 피보나치 수 출력 후 종료
	}
	return 0; }
