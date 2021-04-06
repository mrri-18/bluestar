#include<iostream>
using namespace std;
int main()
{
	int res;
	int seat[4][10] = { 0 }; //배열 모두 0으로 초기화


	cout << "좌석을 예약하시겠습니까? (1또는0) ";
	cin >> res;
	if (res == 1)
	{
		cout << "현재의 좌석은 다음과 같습니다. " << endl;
		//좌석표를 보여준다.
		cout << "-------------------------------------" << endl;
		cout << "1 2 3 4 5 6 7 8 9 10 " << endl;
		cout << "-------------------------------------" << endl;
		for (int i = 1; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				cout << seat[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if (res == 0)
		cout << "좌석 예약 종료" << endl;
	else
		cout << "정수 1또는 0을 입력하세요. " << endl;
	while (res == 1) //좌석을 예약하는 상황동안 작동
	{
		int x, y;
		cout << "몇 열, 몇 번째 좌석을 예약하시겠습니까? ";
		cin >> x;
		cin >> y;
		if (seat[x][y] == 0)
		{
			cout << "예약되었습니다." << endl;
			seat[x][y-1] = 1;
			cout << "-------------------------------------" << endl;
			cout << "1 2 3 4 5 6 7 8 9 10 " << endl;
			cout << "-------------------------------------" << endl;
			for (int i = 1; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					cout << seat[i][j] << " ";
				}
				cout << endl;
			}

		}
		if(seat[x][y]==1)
		    cout << "이미 예약된 자리 입니다." << endl; //다시 다른 자리를 예약하도록 while문 사용
	}

	
	
	return 0;
}
