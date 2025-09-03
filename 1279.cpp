#include <algorithm>
#include <iostream>
#define N 2003

using namespace std;

int n, m;
string a, b;
int k;

int dp[N][N];

int main() {
    cin >> a >> b;
    n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + k;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] + k;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min({dp[i - 1][j - 1] + abs(a[i] - b[j]),
                            dp[i - 1][j] + k, dp[i][j - 1] + k});
        }
    }
    cout << dp[n][m];
    return 0;
}
