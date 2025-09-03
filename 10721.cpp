#include <algorithm>
#include <iostream>
#define int long long
#define N   21
#define M   100005

using namespace std;

int n, m;
int a[N];
string s;

int b[M], cnt;
bool flag = false;
int ans;

int dp[M];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m / 3; j++) {
            dp[j] = max(dp[j], dp[j - i] + a[i]);
        }
    }
    cin >> s;
    for (int i = 0; i < m - 2; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
            if (!flag) {
                b[++cnt]++;
            } else {
                b[cnt]++;
            }
            flag = true;
            i += 2;
        } else {
            flag = false;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        ans += dp[b[i]];
    }
    cout << ans;
    return 0;
}
