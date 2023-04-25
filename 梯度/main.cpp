#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;

double run(double x, bool& last)
{
	if (rand() % 2)
	{
		last = 1;
		return x;
	}
	else
	{
		last = 0;
		return x * static_cast<double>(-1);
	}
}

double function(double a, double b)
{
	double base_money = 100000; //����
	double base = 100;//��ʼͶ���ʽ�
	bool last = 1;//��һ�ε���Ӯ
	int count = 100;//Ͷ�ʴ���
	for (int i = 0; i < count; ++i)
	{
		if (last)
		{
			base *= a;
		}
		else
		{
			base *= b;
		}
		base_money += run(base, last);
	}
	return base_money;
}

class AI
{
public:
	AI(double a, double b, double c):x(a),y(b),step(c) {}
	void dfuc(long double accuracy)//accuracy��ȷ��,dfuc���ڼ���dx,dy
	{
		dx = function(x + accuracy, y) - function(x, y) / accuracy;
		dy = function(x, y + accuracy) - function(x, y) / accuracy;
	}
	void forward()
	{
		double temp = sqrt(dx * dx + dy * dy);
		x += step * (dx / temp);
		y += step * (dy / temp);
		if(x<0)
		{
			x = 0;
		}
		if (y < 0)
		{
			y = 0;
		}
	}
	void begin(int count)
	{
		for (int i = 0; i < count; ++i)
		{
			dfuc(0.0001);//�󵼾�ȷ�����������
			forward();
			cout << "���Ϊ��" << function(x, y) << endl;
			//show();
		}
	}
	void show()const
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}
private:
	double x, y,dx,dy,step;
};

int main()
{
	srand(time(NULL));
	AI a1(1, 1, 0.001);
	a1.begin(2000);
	a1.show();
}