#include<iostream>
#include<cstdlib>    //cǥ�� ��ƿ��Ƽ�Լ��� ���� �������(ex.���� ����/���� ����/�˻� �� ���� �Լ� ���� ����)
#include<ctime>    //time�� ����Ű�� �ð�, �ʴ��� �ð��� ���ڿ��� ��ȯ�ϴ� 
using namespace std;

class random {
public:
	random();    //������
	int next();
	int nextInrange(int x, int y);
	
};

random::random() {
	srand((unsigned)time(0));   //������ ������ ������ ������ �߻�
}
int random::next() {
	int number;
	while (1) {
		number = rand();
		if (number % 2 == 0) break;
	}
	return number;
}//������ ¦�� ������ ��ȯ�ϴ� �Լ�

int random::nextInrange(int x, int y) {
		int number;
		while (1) {
			number = rand() % (y - x + 1) + x;
			if (number % 2 != 0) break;
		}
		return number;
}
            //������ ������ Ȧ�� ������ ��ȯ�ϴ� �Լ� 
int main() {
	random r;
	int list[10];
	cout << "-- 0���� " << 32767 << "������ ¦�� ���� ���� 10 ��--" << endl;  //���� �Լ��� ȣ���ؼ� ���� ���� ���
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "== 2���� " << "30 ������ Ȧ�� ���� ���� 10 �� --(��, �ߺ��Ǵ� ���� ����� ��)" << endl;
	for (int i = 0; i < 10; i++) {
	again:; 
		int n = r.nextInrange(2,30);
		for (int j = 0; j < 9; j++)
			if (n == list[j])
				goto again;      //�ߺ��Ǵ� ���� �ִٸ� �ٽ� ���ư�
		list[i] = n;		
	}
	for(int i=0;i<10;i++)         //�迭�� ����� ���� Ȧ�� ��� 
		cout << list[i] << ' ';		
	cout << endl;
}