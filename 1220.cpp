#include <iostream>
#define N   51
#define INF 0x5f5f5f5f

using namespace std;

int n, c;
int pos[N], w[N];
int dp[N][N][2];

int f(int l, int r, int cur, int t) {
    int d = cur == l - 1 ? pos[l] - pos[cur] : pos[cur] - pos[r];
    int t1 = ((t ^ 0) * (pos[r] - pos[l])) + d;
    int t2 = ((t ^ 1) * (pos[r] - pos[l])) + d;
    // cout << l << " " << r << " " << d << " " << t1 << " " << t2 << '\n';
    return min(dp[l][r][0] + (t1 * (w[n] - (w[r] - w[l - 1]))),
               dp[l][r][1] + (t2 * (w[n] - (w[r] - w[l - 1]))));
}

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i] >> w[i];
        w[i] += w[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dp[c][c][0] = dp[c][c][1] = 0;
    for (int l = 1; l < n; l++) {
        for (int i = 1; i + l <= n; i++) {
            int j = i + l;
            dp[i][j][0] = f(i + 1, j, i, 0);
            dp[i][j][1] = f(i, j - 1, j, 1);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << i << " " << j << " " << dp[i][j][0].first << " "
    //              << dp[i][j][0].second << " " << dp[i][j][1].first << " "
    //              << dp[i][j][1].second << '\n';
    //     }
    // }
    cout << min(dp[1][n][0], dp[1][n][1]);
    return 0;
}
