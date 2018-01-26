#include<iostream>
using namespace std;

int main()
{
	int L; int time = 0;
	cin >> L;
	int **a = new int *[L];
	for (int i = 0; i < L; ++i)
		a[i] = new int[L];
	int **b = new int *[L];
	for (int i = 0; i < L; ++i)
		b[i] = new int[L];					//见两个二维数组，一个用来保存原始数据，一个用来处理数据
	for (int i = 0; i < L; ++i)
		for (int j = 0; j < L; ++j)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	bool flag = false;						//繁衍停止的结束标志
	while (!flag)
	{
		for (int i = 0; i < L; ++i)
			for (int j = 0; j < L; ++j)
			{
				if (a[i][j] == 1)
				{
					if (i >= 1 && b[i - 1][j] != 2)
						b[i - 1][j] = 1;
					if (i + 1 < L && b[i + 1][j] != 2)
						b[i + 1][j] = 1;
					if (j + 1 < L && b[i][j + 1] != 2)
						b[i][j + 1] = 1;
					if (j >= 1 && b[i][j - 1] != 2)
						b[i][j - 1] = 1;					//该培养基格子有细菌，附近格子没有抗生素就繁殖，然后将自己定义为抗生素减少处理
					b[i][j] = 2;
				}
			}
		++time;
		flag = true;
		for(int i=0;i<L;++i)
			for (int j = 0; j < L; ++j)
			{
				if (b[i][j] == 0)
					flag = false;							//判断还有没有空的格子，
				a[i][j] = b[i][j];
			}												//判断还有没有空的格子，将处理完一遍的数据复制给原数据数组，进入下一个处理循环
	}
	cout << time << endl;
	system("pause");
	return 0;
}