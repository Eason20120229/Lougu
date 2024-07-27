#include <iostream>

using namespace std;

long long a[100001], tree[400001], tag[400001];

inline int ls(int p)
{
    return p << 1;
}

inline int rs(int p)
{
    return p << 1 | 1;
}

inline void add_tag(int p, int l, int r, long long k)
{
    tag[p] += k;
    tree[p] += (r - l + 1) * k;
}

inline void push_up(int p)
{
    tree[p] = tree[ls(p)] + tree[rs(p)];
}

inline void push_down(int p, int l, int r)
{
    if (tag[p])
    {
        int m = (l + r) >> 1;
        add_tag(ls(p), l, m, tag[p]);
        add_tag(rs(p), m + 1, r, tag[p]);
        tag[p] = 0;
    }
}

inline void buildtree(int p, int l, int r)
{
    tag[p] = 0;
    if (l == r)
    {
        tree[p] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    buildtree(ls(p), l, m);
    buildtree(rs(p), m + 1, r);
    push_up(p);
}

inline void update(int p, int l, int r, int x, int y, long long k)
{
    if (x <= l && r <= y)
    {
        add_tag(p, l, r, k);
        return;
    }
    push_down(p, l, r);
    int m = (l + r) >> 1;
    if (x <= m)
        update(ls(p), l, m, x, y, k);
    if (y > m)
        update(rs(p), m + 1, r, x, y, k);
    push_up(p);
}

inline long long calc(int p, int l, int r, int x, int y)
{
    if (x <= l && r <= y)
    {
        return tree[p];
    }
    long long res = 0;
    push_down(p, l, r);
    int m = (l + r) >> 1;
    if (x <= m)
        res += calc(ls(p), l, m, x, y);
    if (y > m)
        res += calc(rs(p), m + 1, r, x, y);
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    buildtree(1, 1, n);
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            long long k;
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        } else
        {
            int x, y;
            cin >> x >> y;
            cout << calc(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
