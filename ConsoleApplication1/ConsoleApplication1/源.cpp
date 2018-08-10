#include <iostream>  
#include <string>  
#include <vector>  
#include <algorithm>  
using namespace std;
int main() {
	/*��Ʒ����*/
	int n = 4;
	/*��������*/
	int cap = 10;
	int v[4] = { 40,25,12,40 };
	int w[4] = { 4,5,7,3 };
	/*��ά��̬�滮��*/
	vector<int> p(cap + 1, 0);
	vector<vector<int>> dp(n + 1, p);
	cout << dp[0][0] << endl;
	for (int i = 1; i <= n; i++) {/*ö����Ʒ*/
		for (int j = 1; j<cap + 1; j++) {/*ö������*/
										 /*�ж�ö�ٵ������͵�ǰѡ�����Ʒ�����Ĺ�ϵ
										 ���ö�ٵĺ��������ڵ���ѡ����Ʒ������Ҫ�ж��Ƿ�ѡ��ǰ��Ʒ*/
			if (j - w[i - 1] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
			else
				/*���ö�ٵ�������û�е�ǰѡ����Ʒ���������Ǿ�ֻ���ǲ�ȡ��ǰ��Ʒ*/
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][cap] << endl;

	system("pause");
	return 0;
}
