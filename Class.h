#ifndef Class_h
#define Class_h

class oval {
private:
	int A, B = 0;
public:  //멤버변수 정의
	oval();
	oval(int p, int q);
	int getA();
	int getB();
	void Area();
	void set(int x, int y);
	~oval();
};

#endif Class_h