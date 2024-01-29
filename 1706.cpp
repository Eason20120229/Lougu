/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-27 18:07
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int s;
int vis[10];
bool book[10];

void dfs(int n) {
	if (n == s + 1) {
		for (int i = 1; i <= s; i++) {
			cout << "    " << vis[i];
		}
		cout << endl;
	}
	for (int i = 1; i <= s; i++) {
		if (!book[i]) {
			book[i] = true;
			vis[n] = i;
			dfs(n + 1);
			book[i] = false;
		}
	}
}


int main() {
	cin >> s;
	dfs(1);
	return 0;
}
