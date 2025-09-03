#include <iostream>
#define N 2003

using namespace std;

int n;
int dp[N][N];
int s[N];
int v[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    for (int l = 0; l < n; l++) {
        for (int i = 1; i + l <= n; i++) {
            int j = i + l;
            if (i == j) {
                dp[i][j] = v[i];
                continue;
            }
            dp[i][j] = max(dp[i + 1][j] + s[j] - s[i] + v[i],
                           dp[i][j - 1] + s[j - 1] - s[i - 1] + v[j]);
        }
    }
    cout << dp[1][n];
    return 0;
}
