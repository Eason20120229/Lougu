/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-12-02 17:14
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
int tree[20001];
int icount = 0;

void f1(int x) {
	if (tree[x] < tree[x / 2]) {
		swap(tree[x], tree[x / 2]);
		f1(x / 2);
	}
}

void f2(int x) {
	if (tree[x] > tree[x * 2] && tree[x * 2] != 0) {
		swap(tree[x], tree[x * 2]);
		f2(x * 2);
	}
	if (tree[x] > tree[x * 2 + 1] && tree[x * 2 + 1] != 0) {
		swap(tree[x], tree[x * 2 + 1]);
		f2(x * 2 + 1);
	}
}

void push(int x) {
	tree[icount++] = x;
	f1(icount - 1);
}

int pop() {
	if (icount == 0)
		return -10001;
	int t = tree[0];
	tree[0] = tree[--icount];
	tree[icount] = 0;
	f2(0);
	return t;
}

int main() {
	freopen("P1090_2.in", "r", stdin);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		push(t);
	}
	while (true) {
		int t = 0;
		t += pop();
		t += pop();
		if (t <= 0)
			break;
		ans += t;
		push(t);
	}
	cout << ans;
	return 0;
}
