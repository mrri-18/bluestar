#include <iostream> 
using namespace std;
int main(){
	int hour=0, min=0, sec=0, cnt;
	cin >> hour >> min >> sec >> cnt;
    hour = hour + cnt / 3600;
	cnt = cnt % 3600;
	min = min + cnt / 60;
	cnt = cnt % 60;
	sec = sec + cnt;
	if (sec >= 60) {
		min = min + sec / 60;
		sec = sec % 60;
	}
	if (min >= 60) {
			hour = hour + min / 60;
			min = min % 60;	
	}
	if (hour > 23)hour = hour % 24;  //hour이 24 이상일 때 24를 빼는 것 >> 24로 나누어 그 나머지만을 계산 
	cout << hour << " " << min << " " << sec << endl;
	return 0; }
