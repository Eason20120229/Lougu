/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-10-19 20:43
    说明:
*********************************************************************/
#include <iostream>
#include <stack>
using namespace std;

stack<int> q;

int main() {
	int n, a = 1;
	cin >> n;
	if ((n & 1) || n == 0) {
		cout << -1;
		return 0;
	}
	while (n) {
		if (n & 1) {
			q.push(a);
		}
		a *= 2;
		n = n / 2;
	}
	cout << q.top();
	q.pop();
	while (!q.empty()) {
		cout << " " << q.top();
		q.pop();
	}
	return 0;
}
