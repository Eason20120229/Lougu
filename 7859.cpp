#include <cstring>
#include <iostream>
#define M 402

using namespace std;

int n, m;
int x[M], y[M];
bool vis[23];
int ans;

bool check() {
    for (int i = 1; i <= m; i++) {
        if (vis[x[i] - 1] && vis[y[i] - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        memset(vis, 0, sizeof vis);
        for (int j = 0; j <= 20; j++) {
            if ((i & (1 << j)) != 0) {
                vis[j] = true;
            }
        }
        if (check()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
