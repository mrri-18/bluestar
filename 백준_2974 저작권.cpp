#include <iostream> 
using namespace std;
int main(){
	int cnt,avg;
	cin >> cnt >> avg;  //목표: cnt*avg의 최솟값을 구함
	cout << cnt * avg-(cnt-1) << endl; //원래식: cnt=결과/avg, cnt의 값은 항상 올림이므로 cnt-1을 빼준다.
	return 0; }
