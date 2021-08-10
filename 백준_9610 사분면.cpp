#include <iostream> 
using namespace std;
int main(){
	int x, y, n, Q1=0, Q2=0, Q3=0, Q4=0, AXIS=0;
	cin >> n;  //case수 입력
	for (int i = 0; i < n; i++) {
		cin >> x >> y;  //x,y좌표에 따라 사분면과 축에 위치한 점의 개수 출력
		if (x > 0 && y > 0)Q1++;
		if (x > 0 && y < 0)Q4++;
		if (x < 0 && y > 0)Q2++;
		if (x < 0 && y< 0)Q3++;
		if (x == 0 || y == 0)AXIS++;
	}
	cout<<"Q1: " << Q1 << "\n" << "Q2: " << Q2 << "\n" << "Q3: " << Q3 << "\n" << "Q4: " << Q4 << "\n" << "AXIS: " << AXIS;
	return 0; }
