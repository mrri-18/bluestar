#include <iostream>
#include<string>    //string 클래스를 사용하기 위한 라이브러리 
using namespace std;
string changeNum(string n) {
    int sum = 0;
    for (int i = 0; i < n.length(); i++) 
        sum += n[i] - '0';    //왜 0을 빼야하는지 공부 
    return to_string(sum);
}
int main() {
    string x;
    int cnt = 0;
    cin >> x;
    while (x.length() != 1) {
        x = changeNum(x);
        cnt++;
    }
    cout << cnt << "\n";
    (x == "3" || x == "6" || x == "9") ? cout << "YES\n" : cout << "NO\n";  //삼항연산자
    return 0;
}
