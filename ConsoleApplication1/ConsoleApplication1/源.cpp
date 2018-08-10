#include <iostream>  
#include <string>  
#include <vector>  
#include <algorithm>  
using namespace std;
int main() {
	/*物品数量*/
	int n = 4;
	/*背包承重*/
	int cap = 10;
	int v[4] = { 40,25,12,40 };
	int w[4] = { 4,5,7,3 };
	/*二维动态规划表*/
	vector<int> p(cap + 1, 0);
	vector<vector<int>> dp(n + 1, p);
	cout << dp[0][0] << endl;
	for (int i = 1; i <= n; i++) {/*枚举物品*/
		for (int j = 1; j<cap + 1; j++) {/*枚举重量*/
										 /*判断枚举的重量和当前选择的物品重量的关系
										 如果枚举的和总量大于等于选择物品，则需要判断是否选择当前物品*/
			if (j - w[i - 1] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
			else
				/*如果枚举的重量还没有当前选择物品的重量大，那就只能是不取当前物品*/
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][cap] << endl;

	system("pause");
	return 0;
}
