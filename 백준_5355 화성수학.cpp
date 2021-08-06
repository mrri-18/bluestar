#include <iostream> 
#include<string>
using namespace std;
int main(){
	double num, cas; string cal;
	cin >> cas;
	for (int i = 0; i < cas; i++) {
		cin >> num; getline(cin, cal, '\n');  //공백 이전까지 저장 
		for (int j = 0; j < cal.length(); j++) {
			if (cal[j] == '@')num = num * 3;
			if (cal[j] == '%')num = num + 5;
			if (cal[j] == '#')num = num -7;
		}
		printf("%.02f\n", num);
	}
	return 0; }

