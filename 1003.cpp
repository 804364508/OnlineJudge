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
		b[i] = new int[L];					//��������ά���飬һ����������ԭʼ���ݣ�һ��������������
	for (int i = 0; i < L; ++i)
		for (int j = 0; j < L; ++j)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	bool flag = false;						//����ֹͣ�Ľ�����־
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
						b[i][j - 1] = 1;					//��������������ϸ������������û�п����ؾͷ�ֳ��Ȼ���Լ�����Ϊ�����ؼ��ٴ���
					b[i][j] = 2;
				}
			}
		++time;
		flag = true;
		for(int i=0;i<L;++i)
			for (int j = 0; j < L; ++j)
			{
				if (b[i][j] == 0)
					flag = false;							//�жϻ���û�пյĸ��ӣ�
				a[i][j] = b[i][j];
			}												//�жϻ���û�пյĸ��ӣ���������һ������ݸ��Ƹ�ԭ�������飬������һ������ѭ��
	}
	cout << time << endl;
	system("pause");
	return 0;
}