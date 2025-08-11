#include <iostream>
#define N   31
#define int long long

using namespace std;

int n, m;
int dp[N][N];

signed main() {
    cin >> n >> m;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            if (i % 2 != 0 || j % 2 != 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
