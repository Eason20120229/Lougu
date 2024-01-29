/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-12-02 16:58
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct oj {
	int s, e;
};

oj a[1000000];

bool cmp(oj i, oj j) {
	return i.e < j.e;
}

int main() {
	int n, t, j = 0;
	int ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].s >> a[i].e;
	}
	sort(a, a + n, cmp);
	t = a[0].e;
	while (j < n) {
		if (a[j].s >= t) {
			t = a[j].e;
			ans++;
		}
		j++;
	}
	cout << ans;
	return 0;
}
