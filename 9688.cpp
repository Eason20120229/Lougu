#include <cstring>
#include <iostream>
#define int long long
#define N   502
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

int n, h;
int a[N], b[N];
int pre[N], las[N];
int dp[N][N];

signed main() {
    memset(las, 0x7f, sizeof las);
    memset(pre, 0x7f, sizeof pre);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (pre[a[i]] == INF) {
            pre[a[i]] = i;
        }
        las[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int ans = -INF;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -INF;
            if (pre[j] == INF) {
                continue;
            }
            if (i == 1) {
                dp[i][j] = b[j];
                continue;
            }
            for (int k = 1; k <= n; k++) {
                if (k < j && las[k] < pre[j] && dp[i - 1][k] != -INF) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + b[j]);
                }
            }
            if (i == h) {
                ans = max(ans, dp[i][j]);
            }
        }
    }
    if (ans == -INF) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}
