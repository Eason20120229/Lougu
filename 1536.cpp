#include <iostream>
#define N 1001

using namespace std;

int n, m;
int fa[N];

int get(int x) {
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}

void solve() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u;
        int v;
        cin >> u >> v;
        fa[get(u)] = get(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (get(i) == i) {
            ans++;
        }
    }
    cout << ans - 1 << '\n';
}

int main() {
    cin >> n;
    while (n != 0) {
        cin >> m;
        solve();
        cin >> n;
    }
    return 0;
}
