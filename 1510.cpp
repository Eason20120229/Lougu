/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-12-03 11:12
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int dp[10001][10001];
int a[10001], b[10001];

int main() {
	int s, m = 0;
	int v, n, c;
	cin >> v >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		m = max(a[i], a[i - 1]);
	}

	for (int i = 1; i <= m; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= n; j++) {
			if (i > a[j]) {
				dp[i][j] = min(dp[i - a[j]][j] + b[j], dp[i][j - 1]);
			} else {
				dp[i][j] = min(dp[0][j] + b[j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[v][n];
	return 0;
}
