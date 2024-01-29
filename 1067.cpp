/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-20 18:56
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int a[101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 0) {
		cout << a[n];
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (a[i] == 1) {
				cout << "x^" << (n - i);
			} else if (a[i] == -1) {
				cout << "-x^" << (n - i);
			} else if (a[i] == 0)
				continue;
			else {
				cout << a[i] << "x^" << (n - i);
			}
		} else if (i == n - 1) {
			if (a[i] == 1) {
				cout << "+x";
			} else if (a[i] == -1) {
				cout << "-x";
			} else if (a[i] == 0)
				continue;
			else if (a[i] < 0) {
				cout << a[i] << "x";
			} else {
				cout << "+" << a[i] << "x";
			}
		} else {
			if (a[i] == 1) {
				cout << "+x^" << (n - i);
			} else if (a[i] == -1) {
				cout << "-x^" << (n - i);
			} else if (a[i] == 0)
				continue;
			else if (a[i] < 0) {
				cout << a[i] << "x^" << (n - i);
			} else {
				cout << "+" << a[i] << "x^" << (n - i);
			}
		}
	}
	if (a[n] != 0) {
		if (a[n] < 0) {
			cout << a[n];
		} else {
			cout << "+" << a[n];
		}
	}
	return 0;
}
