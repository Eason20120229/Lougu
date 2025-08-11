#include <cmath>
#include <iostream>
#define N 1000006
#define M 998244353

using namespace std;

int n;
int fa[2 * N];
int t[N], f[N];

int get(int x) {
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}

long long ksm(long long a, long long b) {
    long long ans = 1;
    a %= M;
    while (b != 0) {
        if ((b & 1) == 1) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int a;
        int opt;
        cin >> a >> opt;
        if (opt == 1) {
            if (get(a) == get(i + n)) {
                cout << "No answer";
                return 0;
            }
            fa[get(a)] = get(i);
            fa[get(a + n)] = get(i + n);
        } else {
            if (get(a) == get(i)) {
                cout << "No answer";
                return 0;
            }
            fa[get(a + n)] = get(i);
            fa[get(a)] = get(i + n);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (get(i) == i) {
            ans++;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (get(i) <= n) {
            if (i <= n) {
                t[get(i)]++;
            } else {
                f[get(i)]++;
            }
        }
    }
    int maxn = 0;
    int minn = 0;
    for (int i = 1; i <= n; i++) {
        if (get(i) == i) {
            maxn += max(t[i], f[i]);
            minn += min(t[i], f[i]);
        }
    }
    cout << ksm(2, ans) << '\n' << maxn << '\n' << minn;
    return 0;
}
