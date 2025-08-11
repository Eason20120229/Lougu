#include <iostream>
#define N 1000006

using namespace std;

int n;
int a[N];
int f[N];
int mask = (1 << 18) - 1;
auto main() -> int {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = 1 << (a[i] - 1);
    }
    for (int l = 1, r = 0, t = 0; l <= n; l++) {
        while (r + 1 <= n && (t & a[r + 1]) == 0) {
            r++;
            t |= a[r];
        }
        f[t] = max(f[t], r - l + 1);
        t ^= a[l];
    }
    for (int i = 0; i < mask; i++) {
        for (int j = 1; j <= mask; j <<= 1) {
            f[i | j] = max(f[i | j], f[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= mask; i++) {
        ans = max(ans, f[i] + f[mask ^ i]);
    }
    cout << ans;
    return 0;
}
