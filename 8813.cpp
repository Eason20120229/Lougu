/*********************************************************************
    ������:8813.cpp
    ��Ȩ:
    ����:
    ����: 2023-10-20 19:56
    ˵��:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long c = 1;
	if (b == 0) {
		cout << 1;
		return 0;
	}
	while (b--) {
		c *= a;
		if (c > pow(10, 9)) {
			cout << -1;
			return 0;
		}
	}
	cout << c;

	return 0;
}
