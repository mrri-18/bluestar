#include <iostream> 
#include <vector>
using namespace std;
int main(){
	int n, result; 
	while (1) {
		cin >> n;
		if (n == -1)break;
		result = 0; vector<int> num;
		for (int i = 1; i <= n/2; i++) {
			if (n % i == 0) {
				num.push_back(i);
				result = result + i;
			}
		}
		cout << n;
		if (n == result) {
			cout << " = ";
			for (int i = 0; i < num.size()-1; i++)cout << num[i] << " + ";
			cout << num[num.size() - 1] << "\n";
			continue;
		}
		cout << " is NOT perfect.\n";
	}
	return 0; }
