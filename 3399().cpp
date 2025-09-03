#include <cstring>
#include <iostream>
#define N 1003

using namespace std;

int n, m;
int dp[N];
int d[N], c[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    memset(dp, 0x7f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = n; j > 0; j--) {
            dp[j] = min(dp[j], dp[j - 1] + (d[j] * c[i]));
        }
        dp[0] = 0;
    }
    cout << dp[n];
    return 0;
}
