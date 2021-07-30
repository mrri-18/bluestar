#include <iostream> 
using namespace std;
int main(){
	int n ,m ; //리스트 작성을 몇 번 할지<<문제 독해 못함, 그 리스트 안의 선수를 결정하는 변수
	char a[100][21] = {}; 
	cin >> n;
	for(int i = 0; i < n; i++){ 
		int b ,l ,max = 0; cin >> m;
		for(int j = 0; j < m; j++){ 
			cin >> b; cin >> a[j];    >>연봉과 이름 입력
			if(b > max){ max = b; l = j;   >>연봉을 따로 저장하지 않고 바로 비교, 갱신
			} 
		} 
		cout << a[l] << endl; } 
	return 0; }

