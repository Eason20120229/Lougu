/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-20 18:27
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int a[101];

int main() {
	int n, last = -1, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] == last)
			continue;
		last = a[i];
		ans++;
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		if (a[i] == last)
			continue;
		last = a[i];
		if (i == 0) {
			cout << a[i];
		} else {
			cout << " " << a[i];
		}
	}
	return 0;
}
