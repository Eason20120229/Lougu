/*

https://www.luogu.com.cn/problem/P2671

*/

#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

long long color[100001];
long long sum = 0;

long long mod(long long x) {
    return x % 10007;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        long long tmp;
        cin >> tmp;
        tmp = mod(tmp);
        arr[i] = mod(arr[i - 1] + tmp);
    }
    for (int i = 1; i <= n; i++) {
        long long c;
        cin >> c;
        color[i] = c;
    }
    for (long long y = 1; y <= n; y++) {
        long long tmp = 0;
        if (y - 1 < n - y) {
            tmp = arr[2 * y - 1] - (arr[y] - arr[y - 1]);
        } else {
            tmp = arr[n] - arr[2 * y - n - 1] -
                  (arr[y] - arr[y - 1]);
        }
        sum += mod(mod(2 * y) * mod(tmp));
        sum = mod(sum);
        cout << sum << " ";
    }
    cout << sum;
    return 0;
}
