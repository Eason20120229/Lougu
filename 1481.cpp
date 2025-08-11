#include <algorithm>
#include <iostream>
#include <string>
#define N 2003

using namespace std;

int n;
string s[N];
int dp[N];
int ans;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        dp[i] = 1;
    }
    sort(s + 1, s + n + 1, [](string a, string b) {
        return a.size() < b.size();
    });
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (s[i].substr(0, s[j].size()) == s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
