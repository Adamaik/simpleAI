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
	double base_money = 100000; //本金
	double base = 100;//初始投资资金
	bool last = 1;//上一次的输赢
	int count = 100;//投资次数
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
	void dfuc(long double accuracy)//accuracy精确度,dfuc用于计算dx,dy
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
			dfuc(0.0001);//求导精确度在这里调节
			forward();
			cout << "结果为：" << function(x, y) << endl;
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