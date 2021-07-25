#include <iostream>
#include<cmath>
using namespace std;
int main() {
    int a, b, result = 0, sqr[10000] = {};   //처음에 런타임 오류가 났었는데 배열의 크기를 100->10000으로 증가시켜주어 해결 
    cin>> a;
    cin >> b;
    for (int i = a; i <= b; i++) {
        if (sqrt(i) - (int)sqrt(i) == 0) {    //완전 제곱수를 찾기 위해 제곱근 활용
            result += i;
            sqr[i-a]=i;    //'i-a'과정은 필요없는 것 같음. 메모리 낭비를 줄이기위해서 생각해본 방식 
        }
    }
    if (result == 0) cout << -1 << endl;    //완전제곱수가 없다면 더해진 값이 없으므로 result값이 0이라면 완전제곱수가 범위에 없는 것으로 판단하고 -1출력
    for (int i = 0; i < 10000; i++) {
        if (sqr[i] != 0) {    //0이와 저장한 값= 제곱수를 저장한 것, 그 중 가장 먼저 저장된 것(=최소값)이 있다면 출력
            cout<<result<<endl << sqr[i] << endl;
            break;
        }
    }
    return 0;
}
