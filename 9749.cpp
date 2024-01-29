/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-12-03 09:16
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll n, d, s = 0, i = 1, ans = 0;
	cin >> n >> d;
	ll v[100000] = {};
	ll a[100000] = {};
	for (ll i = 1; i < n; i++) {
		cin >> v[i];
		v[i] = v[i - 1] + v[i];
	}
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll last = 0;
	while (i < n - 1) {
		if (a[i] < a[last]) {
			ll t = v[i] - v[last] - s;
			ll h;
			if (t % d == 0) {
				h = t / d * a[last];
				ans += h;
				s = 0;
			} else {
				h = (t / d + 1) * a[last];
				ans += h;
				s = d - t % d;
			}
			last = i;
		}
		i++;
	}
	ll t = v[n - 1] - v[last] - s;
	ll h;
	if (t % d == 0) {
		h = t / d * a[last];
		ans += h;
	} else {
		h = (t / d + 1) * a[last];
		ans += h;
	}
	cout << ans;
	return 0;
}
