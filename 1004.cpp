#include <iostream>
using namespace std;

int main()
{
	int timeLimit, u_time, f_time, d_time, num;
	char *ch;
	cin >> timeLimit >> num >> u_time >> f_time >> d_time;
	ch = new char[num];					//����·��
	for (int i = 0; i < num; ++i)
		cin >> ch[i];
	int *time = new int[num];
	for (int i = 0; i < num; ++i)
	{
		if (ch[i] == 'u' || ch[i] == 'd')
			time[i] = u_time + d_time;
		else
			time[i] = 2 * f_time;
	}									//��ʱ�����鱣��ĳһ��·����������ʱ��
	bool flag = true;					//�ж��Ƿ��ܹ���ʱ������־
	int sumTime = 0, temp = 0;			//��¼����ĳһ��·����ʱ��
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