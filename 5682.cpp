/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-19 19:25
    说明:
*********************************************************************/
#include <cstdio>

long long a[100000], b[2];
long long c[99500][99500];

int main() {
	long long n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || a[j] == 0)
				continue;
			int t = 0;
			if (c[i][j] != 0) {
				t = c[i][j];
			} else {
				t = a[i] % a[j];
				c[i][j] = t;
			}
			if (b[0] < t) {
				b[1] = b[0];
				b[0] = t;
			} else if (b[1] < t && b[0] != t) {
				b[1] = t;
			}
		}
	}
	if (b[1] == 0) {
		printf("%d", -1);
	} else {
		printf("%d", b[1]);
	}
	return 0;
}
