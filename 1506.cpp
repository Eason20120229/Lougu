/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-28 07:08
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char oibh[502][502];
bool book[502][502];
int n, m, ans = 0;

void dfs(int x, int y) {
	if (oibh[x][y] == '0') {
		oibh[x][y] = '1';
	}
	for (int i = 0; i < 4; i++) {
		int tx = x + way[i][0];
		int ty = y + way[i][1];
		if (!book[tx][ty] && tx <= n + 1 && ty <= m + 1 && tx >= 0 && ty >= 0) {
			if (oibh[tx][ty] != '*') {
				book[tx][ty] = true;
				dfs(tx, ty);
				book[tx][ty] = false;
			}
		}
	}
}

int main() {
	freopen("P1506_1.in", "r", stdin);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		scanf("%s", oibh[i]);
	}
	dfs(0, 0);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << oibh[i][j] << " ";
			if (oibh[i][j] == '0') {
				ans++;
			}
		}
		cout << endl;
	}
	cout << ans;
	return 0;
}
