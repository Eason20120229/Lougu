#include <cstring>
#include <iostream>
#include <string>
#define N 1003

using namespace std;

int n, m;
string s, t;
int dp[N][N];

int main() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    s = " " + s, t = " " + t;
    memset(dp, 0x5f, sizeof dp);
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (s[i] == t[j]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
