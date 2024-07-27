#include <bits/stdc++.h>
#define N         500001
#define lowbit(x) ((x) & (-x))
using namespace std;

struct node
{
    long long val;
    long long idt;
} input[N];

long long n;
long long tree[N];
long long ran[N];

auto cmp(node a, node b) -> bool
{
    return a.val < b.val;
}

void update(long long i, long long d)
{
    while (i <= n)
    {
        tree[i] += d;
        i += lowbit(i);
    }
}

long long sum(long long i)
{
    long long x = 0;
    while (i)
    {
        x += tree[i];
        i -= lowbit(i);
    }
    return x;
}

auto main() -> int
{
    long long ans = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &input[i].val);
        input[i].idt = i;
    }
    sort(input + 1, input + n + 1, cmp);
    for (long long i = 1; i <= n; i++)
    {
        ran[input[i].idt] = i;
        if (input[i].val == input[i - 1].val)
        {
            ran[input[i].idt] = ran[input[i - 1].idt];
        }
    }
    for (long long i = n; i > 0; i--)
    {
        update(ran[i], 1);
        ans += sum(ran[i] - 1);
    }
    // for (long long i = 1; i <= n; i++)
    // {
    //     cout << ran[i] << " ";
    // }
    cout << ans;
    return 0;
}
