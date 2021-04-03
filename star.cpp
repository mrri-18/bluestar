#include<iostream>
using namespace std;
int main()
{
	int N;
	int n = 0;

	cout << "정수를 입력하세요: ";
	cin >> N;
	if (N < 2)//N이 2미만인 정수일 때
		cout << "2이상 정수를 입력하세요" << endl;

    if (N % 2==0)//N이 짝수인 경우
		for (int j = 0; j < N; j++) //N개의 별을 N번 출력함
		{
			for (int i = 0; i < N / 2; i++) //N개의 별을 출력함
			{
				cout << "* ";
				n = n + 1;
			}
			cout << "\n";
			for (int i = 0; i < (N / 2); i++)
			{
				cout << " *";
				n = n + 1;

			}
			cout << "\n";
		}
	if (N % 2 == 1)//N이 홀수인 경우
		for (int j = 0; j < N; j++) //N개의 별을 N번 출력함
		{
			for (int i = 0; i < (N/2)+1; i++) //N개의 별을 출력함
			{
				cout << "* ";
				n = n + 1;
			}
			cout << "\n";
			for (int i = 0; i < (N / 2); i++)
			{
				cout << " *";
				n = n + 1;

			}
			cout << "\n";
		}
		
		

	}
      
	        






