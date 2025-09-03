#include <algorithm>
#include <iostream>
#define N 202
#define M 1003

using namespace std;

int n, a, b;
int dp[2][M][M];
int w[N];

int old = 1, now = 0;

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= a; j++) {
            for (int k = 0; k <= b; k++) {
                dp[now][j][k] = dp[old][j][k];
                if (j >= w[i]) {
                    dp[now][j][k] =
                        max(dp[now][j][k], dp[old][j - w[i]][k] + w[i]);
                }
                if (k >= w[i]) {
                    dp[now][j][k] =
                        max(dp[now][j][k], dp[old][j][k - w[i]] + w[i]);
                }
            }
        }
        swap(now, old);
    }
    cout << dp[old][a][b];
    return 0;
}
