#include <cmath>
#include <iostream>
#define N 41
#define M (N * N)

using namespace std;

int n;
int l[N];
int s[N];
int sum;

bool dp[N][M][M];

void init() {
    dp[0][0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s[i]; j++) {
            for (int k = 0; j + k <= s[i]; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= l[i]) {
                    dp[i][j][k] |= dp[i - 1][j - l[i]][k];
                }
                if (k >= l[i]) {
                    dp[i][j][k] |= dp[i - 1][j][k - l[i]];
                }
                // cout << i << " " << j << " " << k << " " << dp[i][j][k] <<
                // '\n';
            }
        }
    }
}

bool chk(int a, int b) {
    return dp[n][a][b];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        s[i] = s[i - 1] + l[i];
        sum += l[i];
    }
    init();
    int ans = -1;
    for (int i = 1; i < sum; i++) {
#define tl (sum - i - j)
        for (int j = i; tl >= j && (j - i) < tl && tl < (i + j); j++) {
            if (chk(i, j)) {
                long double tmp = ((i * i) + (tl * tl) - (j * j)) / (2.0L * tl);
                long double h = sqrt((i * i) - (tmp * tmp));
                ans = max(ans, static_cast< int >(floor(tl * h * 50)));
            }
        }
#undef tl
    }
    cout << ans;
    return 0;
}
