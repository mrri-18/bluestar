#include<iostream>
using namespace std;
int main()
{
	int N;
	int n = 0;

	cout << "������ �Է��ϼ���: ";
	cin >> N;
	if (N < 2)//N�� 2�̸��� ������ ��
		cout << "2�̻� ������ �Է��ϼ���" << endl;

    if (N % 2==0)//N�� ¦���� ���
		for (int j = 0; j < N; j++) //N���� ���� N�� �����
		{
			for (int i = 0; i < N / 2; i++) //N���� ���� �����
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
	if (N % 2 == 1)//N�� Ȧ���� ���
		for (int j = 0; j < N; j++) //N���� ���� N�� �����
		{
			for (int i = 0; i < (N/2)+1; i++) //N���� ���� �����
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
      
	        






