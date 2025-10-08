#include <cmath>
#include <iostream>
#include <queue>
#define ll long long
#define N  100005
#define M  1000006

using namespace std;

struct Node {
    int cur;
    int tot;
    int price;
    int reduce;
    const bool operator<(Node o) const {
        return price < o.price;
    }
};

int n, m, k;
int fa[N], rest[N];
ll ans[M];

priority_queue< Node > q;

int ffa(int x) {
    return x == fa[x] ? x : fa[x] = ffa(fa[x]);
}

void mfa(int a, int b) {
    a = ffa(a), b = ffa(b);
    if (a != b) {
        fa[a] = b;
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i < N; i++) {
        fa[i] = i;
        rest[i] = m;
    }
    for (int i = 1; i <= n; i++) {
        int a;
        int s;
        int c;
        int x;
        cin >> a >> s >> c >> x;
        q.push(Node{1, c, a + s, x});
        if (c > 1) {
            q.push(Node{c - 1, c - 1, a, x});
        }
    }
    int pos = 0;
    while (!q.empty()) {
        Node p = q.top();
        q.pop();
        int day;
        if (p.reduce == 0) {
            day = N - 1;
        } else {
            day = min(N - 1, static_cast< int >(ceil(1.0 * p.tot / p.reduce)));
        }

        day = ffa(day);
        if (day == 0) {
            continue;
        }
        if (--rest[day] == 0) {
            mfa(day, day - 1);
        }
        if (p.cur > 1) {
            q.push(Node{p.cur - 1, p.tot - 1, p.price, p.reduce});
        }
        pos++;
        ans[pos] = ans[pos - 1] + p.price;
    }
    for (int i = 1; i <= k; i++) {
        int p;
        cin >> p;
        cout << ans[(min(m * p, pos))] << '\n';
    }
    return 0;
}
