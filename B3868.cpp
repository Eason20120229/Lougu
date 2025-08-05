#include <bits/stdc++.h>
using namespace std;
int a[1001][5];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a[i][1] = 1;
        a[i][2] = 1;
        a[i][3] = 1;
        a[i][4] = 1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] > '1' || s[j] < '0') {
                a[i][1] = 0;
            }
            if (s[j] >= '8' || s[j] < '0') {
                a[i][2] = 0;
            }
            if (s[j] > '9' || s[j] < '0') {
                a[i][3] = 0;
            }
            if (s[j] > 'F' || s[j] < '0' ||
                (s[j] < 'A' && s[j] > '9')) {
                a[i][4] = 0;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d %d\n", a[i][1] % 2, a[i][2] % 2,
               a[i][3] % 2, a[i][4] % 2);
    }
    return 0;
}
