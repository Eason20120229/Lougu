#include <iostream>
#include <string>
#define N 301
#define M 1000000007

using namespace std;

int n;
int q;

long long dp[N][N][N][3];
long long ans[N][N];
long long s[N][N];

string str;
long long cnt[3];

int main() {
    cin >> n >> q;
    cin >> str;
    str = " " + str;
    for (int i = 1; i <= n; i++) {
        if (str[i] == 'a') {
            cnt[0]++;
        } else if (str[i] == 'b') {
            cnt[1]++;
        } else if (str[i] == 'c') {
            cnt[2]++;
        }
    }
    if (str[1] == 'a') {
        dp[1][0][0][0] = 1;
        dp[1][1][0][1] = 0;
        dp[1][0][1][2] = 0;
    } else if (str[1] == 'b') {
        dp[1][0][0][0] = 0;
        dp[1][1][0][1] = 1;
        dp[1][0][1][2] = 0;
    } else if (str[1] == 'c') {
        dp[1][0][0][0] = 0;
        dp[1][1][0][1] = 0;
        dp[1][0][1][2] = 1;
    } else {
        dp[1][0][0][0] = 1;
        dp[1][1][0][1] = 1;
        dp[1][0][1][2] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int k = i - j;
            if (str[i] == 'a') {
                dp[i][j][k][1] = 0;
                dp[i][j][k][2] = 0;
            } else if (str[i] == 'b') {
                dp[i][j][k][1] = dp[i - 1][j - 1][k][2];
                dp[i][j][k][2] = 0;
            } else if (str[i] == 'c') {
                dp[i][j][k][1] = 0;
                dp[i][j][k][2] = dp[i - 1][j][k - 1][1];
            } else {
                dp[i][j][k][1] = dp[i - 1][j - 1][k][2];
                dp[i][j][k][2] = dp[i - 1][j][k - 1][1];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (str[i] == 'c') {
                dp[i][j][0][0] = 0;
                dp[i][j][0][1] = 0;
            } else if (str[i] == 'a') {
                dp[i][j][0][0] = dp[i - 1][j][0][1];
                dp[i][j][0][1] = 0;
            } else if (str[i] == 'b') {
                dp[i][j][0][0] = 0;
                dp[i][j][0][1] = dp[i - 1][j - 1][0][0];
            } else {
                dp[i][j][0][0] = dp[i - 1][j][0][1];
                dp[i][j][0][1] = dp[i - 1][j - 1][0][0];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k < i; k++) {
            if (str[i] == 'b') {
                dp[i][0][k][0] = 0;
                dp[i][0][k][2] = 0;
            } else if (str[i] == 'a') {
                dp[i][0][k][0] = dp[i - 1][0][k][2];
                dp[i][0][k][2] = 0;
            } else if (str[i] == 'c') {
                dp[i][0][k][0] = 0;
                dp[i][0][k][2] = dp[i - 1][0][k - 1][0];
            } else {
                dp[i][0][k][0] = dp[i - 1][0][k][2];
                dp[i][0][k][2] = dp[i - 1][0][k - 1][0];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; j + k < i; k++) {
                if (str[i] == 'a') {
                    dp[i][j][k][0] =
                        (dp[i - 1][j][k][1] + dp[i - 1][j][k][2]) % M;
                    dp[i][j][k][1] = 0;
                    dp[i][j][k][2] = 0;
                } else if (str[i] == 'b') {
                    dp[i][j][k][0] = 0;
                    dp[i][j][k][1] =
                        (dp[i - 1][j - 1][k][0] + dp[i - 1][j - 1][k][2]) % M;
                    dp[i][j][k][2] = 0;
                } else if (str[i] == 'c') {
                    dp[i][j][k][0] = 0;
                    dp[i][j][k][1] = 0;
                    dp[i][j][k][2] =
                        (dp[i - 1][j][k - 1][0] + dp[i - 1][j][k - 1][1]) % M;
                } else {
                    dp[i][j][k][0] =
                        (dp[i - 1][j][k][1] + dp[i - 1][j][k][2]) % M;
                    dp[i][j][k][1] =
                        (dp[i - 1][j - 1][k][0] + dp[i - 1][j - 1][k][2]) % M;
                    dp[i][j][k][2] =
                        (dp[i - 1][j][k - 1][0] + dp[i - 1][j][k - 1][1]) % M;
                }
                // cout << i << " " << j << " " << k << " " << dp[i][j][k][0]
                //      << " " << dp[i][j][k][1] << " " << dp[i][j][k][2] <<
                //      '\n';
            }
        }
    }
    for (int j = 0; j <= n; j++) {
        for (int k = 0; j + k <= n; k++) {
            ans[j][k] =
                ((dp[n][j][k][0] + dp[n][j][k][1]) % M + dp[n][j][k][2]) % M;
            // cout << j << " " << k << " " << ans[j][k] << '\n';
        }
    }
    // cout << '\n';
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            int l1 = 0;
            int l2 = 0;
            int l3 = 0;
            if (j != 0) {
                l1 = s[j - 1][k];
            }
            if (k != 0) {
                l2 = s[j][k - 1];
            }
            if (j != 0 && k != 0) {
                l3 = s[j - 1][k - 1];
            }
            s[j][k] = ((((l1 + l2) % M - l3) % M + ans[j][k]) % M + M) % M;
            // cout << j << " " << k << " " << s[j][k] << '\n';
        }
    }
    for (int i = 1; i <= q; i++) {
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        long long a = x + cnt[0];
        long long b = y + cnt[1];
        long long c = z + cnt[2];

        long long ll1 = max(0LL, n - a - c);
        long long ll2 = max(0LL, n - a - b);
        long long l1 = 0;
        long long l2 = 0;
        long long l3 = 0;
        if (ll1 != 0) {
            l1 = s[ll1 - 1][c];
        }
        if (ll2 != 0) {
            l2 = s[b][ll2 - 1];
        }
        if (ll1 != 0 && ll2 != 0) {
            l3 = s[ll1 - 1][ll2 - 1];
        }
        long long ans = ((((s[b][c] - l1) % M - l2) % M + l3) % M + M) % M;
        cout << ans << '\n';
    }
    return 0;
}
