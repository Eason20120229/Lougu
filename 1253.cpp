#include <iostream>
#define INF   0x7fffffff
#define ls(x) x << 1
#define rs(x) x << 1 | 1
#define N     1000001

using std::cin, std::max;

int arr[N];
int lazy[N << 4];
int lazy2[N << 4];
int value[N << 4];

void push_up(int cur)
{
    value[cur] = max(value[ls(cur)], value[rs(cur)]);
}

void maketag_add(int cur, int val)
{
    lazy[cur] += val;
    value[cur] += val;
}

void maketag_chan(int cur, int val)
{
    lazy[cur] = 0;
    lazy2[cur] = val;
    value[cur] = val;
}

void push_down(int cur)
{
    if (lazy2[cur] != -INF)
    {
        maketag_chan(ls(cur), lazy2[cur]);
        maketag_chan(rs(cur), lazy2[cur]);
        lazy2[cur] = -INF;
    }
    if (lazy[cur] != 0)
    {
        maketag_add(ls(cur), lazy[cur]);
        maketag_add(rs(cur), lazy[cur]);
        lazy[cur] = 0;
    }
}

void build(int cur, int curl, int curr)
{
    lazy2[cur] = -INF;
    value[cur] = -INF;
    if (curl == curr)
    {
        value[cur] = arr[curl];
        return;
    }
    int mid = (curl + curr) >> 1;
    build(ls(cur), curl, mid);
    build(rs(cur), mid + 1, curr);
    push_up(cur);
}

// void out(int cur, int curl, int curr)
// {
//     printf("%d %d %d %d\n", cur, curl, curr, value[cur]);
//     if (curl == curr)
//     {
//         return;
//     }
//     int mid = (curl + curr) >> 1;
//     out(ls(cur), curl, mid);
//     out(rs(cur), mid + 1, curr);
// }

void add(int cur, int curl, int curr, int disl, int disr, int val)
{
    if (disl <= curl && curr <= disr)
    {
        maketag_add(cur, val);
        return;
    }
    push_down(cur);
    int mid = (curl + curr) >> 1;
    if (disl <= mid)
    {
        add(ls(cur), curl, mid, disl, disr, val);
    }
    if (disr > mid)
    {
        add(rs(cur), mid + 1, curr, disl, disr, val);
    }
    push_up(cur);
}

void change(int cur, int curl, int curr, int disl, int disr, int val)
{
    if (disl <= curl && curr <= disr)
    {
        maketag_chan(cur, val);
        return;
    }
    push_down(cur);
    int mid = (curl + curr) >> 1;
    if (disl <= mid)
    {
        change(ls(cur), curl, mid, disl, disr, val);
    }
    if (disr > mid)
    {
        change(rs(cur), mid + 1, curr, disl, disr, val);
    }
    push_up(cur);
}

int find(int cur, int curl, int curr, int disl, int disr)
{
    if (disl <= curl && curr <= disr)
    {
        return value[cur];
    }
    push_down(cur);
    int mid = (curl + curr) >> 1;
    int ans = -INF;
    if (disl <= mid)
    {
        ans = find(ls(cur), curl, mid, disl, disr);
    }
    if (disr > mid)
    {
        ans = max(ans, find(rs(cur), mid + 1, curr, disl, disr));
    }
    return ans;
}

int main()
{
    freopen("1253.in", "r", stdin);
    freopen("1253.out", "w", stdout);
    int num;
    int cnt;
    cin >> num >> cnt;
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &arr[i]);
    }
    build(1, 1, num);
    for (int i = 1; i <= cnt; i++)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int disl;
            int disr;
            int val;
            scanf("%d%d%d", &disl, &disr, &val);
            change(1, 1, num, disl, disr, val);
        } else if (opt == 2)
        {
            int disl;
            int disr;
            int val;
            scanf("%d%d%d", &disl, &disr, &val);
            add(1, 1, num, disl, disr, val);
        } else
        {
            int disl;
            int disr;
            scanf("%d%d", &disl, &disr);
            printf("%d\n", find(1, 1, num, disl, disr));
        }
    }
    return 0;
}
