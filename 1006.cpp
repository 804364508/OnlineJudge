#include <iostream>
using namespace std;

//һ����̬�滮
//�������ĺͳ��ָ���������
int main()
{
	int num, *p;
	cin >> num;
	p = new int[num];
	int flag = 0;
	int tmpsum = 0, maxsum = -1000000;
	for (int i = 0; i < num; ++i)
		cin >> p[i];
	for (int i = 0; i < num; ++i)
	{
		tmpsum += p[i];
		++flag;							//������¼�ǲ������г�������Ϊ2
		if (tmpsum <= 0)				//���ָ�ֵ
		{
			tmpsum = 0;	
			flag = 0;
		}
		else if (tmpsum >= maxsum && flag > 1)	//��ǰ���кʹ���maxsum�����ҳ�������Ϊ2
		{
			maxsum = tmpsum;
		}
		else if (tmpsum >= maxsum && flag == 1 && i > 0)	//��ǰ���г���Ϊ1����Ȼ����maxsum����Ҫ����һ��������һ������Ϊ���
		{
			if (tmpsum + p[i - 1] >= maxsum)
				maxsum = tmpsum + p[i - 1];
		}
	}
	if (maxsum > 0)
		cout << maxsum << endl;
	else
		cout << "Game Over" << endl;
	system("pause");
	return 0;
}