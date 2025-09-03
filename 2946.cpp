#include <iostream>
#define int long long
#define N   2003
#define F   1003
#define M   100000000

using namespace std;

int n, f;
int r[N];
int dp[2][F];
int now = 0, old = 1;

signed main() {
    cin >> n >> f;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        r[i] %= f;
    }
    dp[old][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < f; j++) {
            dp[now][j] = (dp[old][j] + dp[old][(j - r[i] + f) % f]) % M;
        }
        swap(now, old);
    }
    cout << dp[old][0] - 1;  // 减去 dp[0][0]
    return 0;
}
