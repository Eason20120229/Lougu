#include <iostream>
#include <vector>
#define N 200005

using namespace std;

int n, m;
vector< int > e[N];
int fa[N];
int a[N];
int mp[N];
vector< bool > f;

int get(int x) {
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u;
        int v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    int cnt = 0;
    for (int i = n; i > 0; i--) {
        cnt++;
        for (int j : e[a[i]]) {
            if (mp[j] >= i) {
                if (get(j) != get(a[i])) {
                    fa[get(j)] = get(a[i]);
                    cnt--;
                }
            }
        }
        if (cnt == 1) {
            f.push_back(true);
        } else {
            f.push_back(false);
        }
    }
    for (int i = f.size() - 1; i >= 0; i--) {
        if (f[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
