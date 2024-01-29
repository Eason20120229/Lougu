/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-12-03 09:00
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		b[i] = abs(a[i - 1] - a[i]);
	}
	sort(b + 1, b + n);
	bool flag = true;
	for (int i = 1; i < n; i++) {
		if (b[i] != i) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "Jolly";
	} else {
		cout << "Not jolly";
	}
	return 0;
}
