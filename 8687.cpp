#include <climits>
#include <iostream>
#define N   1048576
#define INF INT_MAX

using namespace std;

int n, m, k;
int dp[N];
int ans = INF;
int minn[N];
int cnt = 0;

void dfs(int x, int c) {
    if (c > n) {
        return;
    }
    cnt++;
    if (minn[x] <= c) {
        return;
    }
    minn[x] = c;
    if (x == 0) {
        ans = min(ans, c);
        return;
    }
    for (int i = x; i > 0; i = (i - 1) & x) {
        if (dp[i] != INF) {
            dfs(x ^ i, c + dp[i]);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    int mask = (1 << m) - 1;
    for (int i = 1; i <= mask; i++) {
        dp[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int i = 1; i <= k; i++) {
            int a;
            scanf("%d", &a);
            if ((sum & (1 << (a - 1))) == 0) {
                sum += 1 << (a - 1);
            }
        }
        dp[sum] = min(dp[sum], 1);
    }
    // for (int i = 0; i <= mask; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << '\n';
    for (int i = 0; i <= mask; i++) {
        for (int j = 0; j < m; j++) {
            if ((i & (1 << j)) != 0) {
                dp[i ^ (1 << j)] = min(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    for (int i = 0; i <= mask; i++) {
        minn[i] = INF;
    }
    dfs(mask, 0);
    // cout << cnt;
    // cout << '\n';
    if (ans == INF) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}

/*

in:
3 4 2
1 3
2 3
4 3

out:
3

*/
