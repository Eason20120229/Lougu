#include <iostream>
#include <string>
#define N 1000006

using namespace std;

int p;
string str;
int a[N];
int s[N];
int shi[N];
int dp[N];
int h[N];

int main() {
    cin >> p;
    cin >> str;
    int n = str.size();
    str = " " + str;
    shi[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = str[i] - '0';
        shi[i] = shi[i - 1] * 10;
        s[i] = s[i - 1] * 10 + a[i];
    }
    long long ans = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if ((s[i] - s[j] * shi[i - j]) % p == 0) {
                dp[i]++;
            }
        }
        ans += dp[i];
    }
    cout << ans;
    return 0;
}
