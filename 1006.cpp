#include <iostream>
using namespace std;

//一个动态规划
//加起来的和出现负数就重置
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
		++flag;							//用来记录是不是序列长度至少为2
		if (tmpsum <= 0)				//出现负值
		{
			tmpsum = 0;	
			flag = 0;
		}
		else if (tmpsum >= maxsum && flag > 1)	//当前序列和大于maxsum，并且长度至少为2
		{
			maxsum = tmpsum;
		}
		else if (tmpsum >= maxsum && flag == 1 && i > 0)	//当前序列长度为1，虽然大于maxsum，需要考虑一个负数加一个正数为最大
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