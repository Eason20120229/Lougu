#include <bits/stdc++.h>

using namespace std;

int tree[1001][1001];
int r, ans;

int main() {
	cin >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tree[i][j];
			if (i > 0) {
				tree[i][j] = tree[i][j] + max(tree[i - 1][j], tree[i - 1][j - 1]);
			}
		}
	}
	ans = tree[r - 1][0];
	for (int i = 1; i < r; i++) {
		if (tree[r - 1][i] > ans)
			ans = tree[r - 1][i];
	}
	cout << ans;
	return 0;
}
