
#include <iostream>
using namespace std;
int main()
{
	int f1, f2, f3, s1, s2, s3, sum;
    char name[8];
    cout << "����� �̸��� �����Դϱ�? : ";
	cin.getline(name, 8); //������ ������ ���ڿ��� �Է¹��� �� �ִ�.
	cout << "�ݰ����ϴ�. " << name << "��\n";
	cout << "apple�� ������ ���Դϱ�?  ";		//������ ���� ������ �Է¹޴´�.
	cin >> f1;
	cout << "banana�� ������ ���Դϱ�? ";
	cin >> f2;
	cout << "orange�� ������ ���Դϱ�? ";
	cin >> f3;
	cout << "apple�� �� �� �ֽ��ϱ�? ";            // ������ ���� ������ �Է¹޴´�.
	cin >> s1;
	cout << "banana�� �� �� �ֽ��ϱ�? ";
	cin >> s2;
	cout << "orange�� �� �� �ֽ��ϱ�? ";
	cin >> s3;
		
	sum = (s1 * f1 + s2 * f2 + s3 * f3) - 500;         //�� ���ݰ� ���������� 500���� �����Ѵ�.
	cout << "��" << sum << "�� �Դϴ�.\n";            //�ѱݾ��� ����Ѵ�.
	return 0;
} 