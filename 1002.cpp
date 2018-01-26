#include <iostream>
using namespace std;

int main()
{
	int L, W;		//长和宽
	cin >> L >> W;
	int **farmyard = new int*[L+1];	     //为了之后的处理，左上各加了一层为0的数据
	for (int i = 0; i < L+1; ++i)
	{
		farmyard[i] = new int[W+1];
	}
	for (int i = 0; i < L + 1; ++i)
		farmyard[i][0] = 0;
	for (int i = 0; i < W + 1; ++i)
		farmyard[0][i] = 0;				//不需要判断左边上边有没有数据
	for(int i=1;i<L+1;++i)
		for (int j = 1; j < W+1; ++j)
		{
			cin >> farmyard[i][j];
			farmyard[i][j] = farmyard[i][j] + farmyard[i][j - 1] + farmyard[i - 1][j] - farmyard[i - 1][j - 1];
		}								//每一个数据为原矩阵左上角的所有数据之和，容斥
	int ans = 0; 
	int temp;
	int a, b;
	cin >> a >> b;
	for(int i=a;i<L+1;++i)
		for (int j = b; j < W + 1; ++j)
		{
			temp = farmyard[i][j] - farmyard[i - a][j] - farmyard[i][j - b] + farmyard[i - a][j - b];
			if (temp > ans)
				ans = temp;
		}
	cout << ans << endl;
	system("pause");
	return 0;
}