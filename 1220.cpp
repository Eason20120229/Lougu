#include <cstring>
#include <iostream>
#define N   51
#define INF 0x5f5f5f5f

using namespace std;

int n, c;
int pos[N], w[N];
pair< int, int > dp[N][N][2];
int s[N];

int get(int l, int r) {
    return s[r] - s[l - 1];
}

pair< int, int > f(int l, int r, int cur, int t) {
    int d = cur == l - 1 ? pos[l] - pos[cur] : pos[cur] - pos[r];
    int t1 = ((t ^ 0) * (pos[r] - pos[l])) + dp[l][r][0].second + d;
    int t2 = ((t ^ 1) * (pos[r] - pos[l])) + dp[l][r][1].second + d;
    return min(make_pair(dp[l][r][0].first + (t1 * w[cur]), t1),
               make_pair(dp[l][r][0].first + (t1 * w[cur]), t2));
}

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i] >> w[i];
        s[i] = s[i - 1] + w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j][0].first = dp[i][j][1].first = INF;
        }
    }
    dp[c][c][0] = dp[c][c][1] = {0, 0};
    for (int i = c - 1; i >= 1; i--) {
        int t = pos[c] - pos[i];
        dp[i][c][0] = {dp[i + 1][c][0].first + (t * w[i]), t};
    }
    for (int i = c + 1; i <= n; i++) {
        int t = pos[i] - pos[c];
        dp[c][i][1] = {dp[c][i - 1][1].first + (t * w[i]), t};
    }
    for (int l = 1; c - l > 0; l++) {
        for (int r = 1; c + r <= n; r++) {
            int i = c - l;
            int j = c + r;
            dp[i][j][0] = min(f(i + 1, j, i, 0), f(i, j - 1, i, 0));
            dp[i][j][1] = min(f(i + 1, j, i, 1), f(i, j - 1, i, 1));
        }
    }
    cout << min(dp[1][n][0].first, dp[1][n][1].first);
    return 0;
}
