#include <bits/stdc++.h>
using namespace std;

struct st {
	int id, t;
} a[1001];

bool cmp(st i, st j) {
	return i.t < j.t;
}

int main() {
	int n;
	double ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		ans += (n - i) * a[i].t;
	}
	cout << a[1].id;
	for (int i = 2; i <= n; i++) {
		cout << " " << a[i].id;
	}
	cout << endl;
	printf("%.2lf", (ans / n));
	return 0;
}
