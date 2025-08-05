#include <bits/stdc++.h>
using namespace std;

int t[10001], c[10001];
long long dp[10000001];

int main() {
    int T;
    int m;
    cin >> T >> m;
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= T; j++) {
            if (j >= t[i]) {
                dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
            } else {
                dp[j] = dp[j];
            }
        }
    }
    cout << dp[T];
    return 0;
}
