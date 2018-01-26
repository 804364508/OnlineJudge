#include <iostream>
using namespace std;

int main()
{
	int timeLimit, u_time, f_time, d_time, num;
	char *ch;
	cin >> timeLimit >> num >> u_time >> f_time >> d_time;
	ch = new char[num];					//保存路况
	for (int i = 0; i < num; ++i)
		cin >> ch[i];
	int *time = new int[num];
	for (int i = 0; i < num; ++i)
	{
		if (ch[i] == 'u' || ch[i] == 'd')
			time[i] = u_time + d_time;
		else
			time[i] = 2 * f_time;
	}									//用时间数组保存某一段路上来回所需时间
	bool flag = true;					//判断是否能够按时回来标志
	int sumTime = 0, temp = 0;			//记录走完某一段路所需时间
	while (flag)
	{
		sumTime += time[temp];
		++temp;
		if (sumTime > timeLimit)
			flag = false;
	}
	cout << temp - 1 << endl;
	system("pause");
	return 0;
}