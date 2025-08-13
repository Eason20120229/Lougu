#include <cstring>
#include <iostream>
#include <string>
#define N 1000006
#define M 131

using namespace std;

int p;
string str;
int a[N];
long long dp[2][M];
int old = 1, now = 0;

int main() {
    cin >> p;
    cin >> str;
    int n = str.size();
    str = " " + str;
    for (int i = 1; i <= n; i++) {
        a[i] = str[i] - '0';
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(dp[now], 0, sizeof dp[now]);
        for (int j = 0; j < p; j++) {
            dp[now][((10 * j) + a[i]) % p] += dp[old][j];
        }
        dp[now][(a[i]) % p]++;
        ans += dp[now][0];
        memcpy(dp[old], dp[now], sizeof dp[old]);
    }
    cout << ans;
    return 0;
}
