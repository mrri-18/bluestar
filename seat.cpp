#include<iostream>
using namespace std;
int main()
{
	int res;
	int seat[4][10] = { 0 }; //�迭 ��� 0���� �ʱ�ȭ

again:
	cout << ' ';
	cout << "�¼��� �����Ͻðڽ��ϱ�? (1�Ǵ�0) ";
	cin >> res;
	if (res == 1)
	{
		cout << "������ �¼��� ������ �����ϴ�. " << endl;
		//�¼�ǥ�� �����ش�.
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
		cout << "�¼� ���� ����" << endl;
	else {
		cout << " ���� 1�Ǵ� 0�� �Է��ϼ���. " << endl;
		goto again;
	}
		

	    
	while (res == 1)
	{
		int x, y;
		cout << "�� ��, �� ��° �¼��� �����Ͻðڽ��ϱ�? ";
		cin >> x;
		cin >> y;
		if (seat[x][y-1] == 0)
		{
			cout << "����Ǿ����ϴ�." << endl;
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
		else if (seat[x][y-1] == 1)
		    cout << "�̹� ����� �ڸ� �Դϴ�." << endl;
	}

	
	
	return 0;
}