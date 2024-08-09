#include <algorithm>
#include <iostream>
#define M   2001
#define N   101
#define MOD 31011

struct node
{
    int start;
    int end;
    int value;
} edge[M];

int num;
int cnt;
int ecnt;
int pcnt;
int fat[N];
int d[M];
int l[M];
int r[M];
int ans = 1;
int sum;

void add(int start, int end, int value)
{
    ecnt++;
    edge[ecnt].start = start;
    edge[ecnt].end = end;
    edge[ecnt].value = value;
}

auto cmp(node one, node two) -> bool
{
    return one.value < two.value;
}

auto find(int cur) -> int
{
    // std::cout << cur << "-" << fat[cur] << " ";
    return cur == fat[cur] ? cur : fat[cur] = find(fat[cur]);
}

void init(int num)
{
    for (int i = 1; i <= num; i++)
    {
        fat[i] = i;
    }
}

void merge(int one, int two)
{
    one = find(one);
    two = find(two);
    if (one != two)
    {
        fat[one] = two;
    }
}

void dfs(int cur, int x, int tnum)
{
    if (cur > r[x])
    {
        sum += static_cast< int >(tnum == d[x]);
        return;
    }
    int tmp[N] = {};
    for (int i = 1; i <= num; i++)
    {
        tmp[i] = fat[i];
    }
    if (find(edge[cur].start) != find(edge[cur].end))
    {
        merge(edge[cur].start, edge[cur].end);
        dfs(cur + 1, x, tnum + 1);
    }
    for (int i = 1; i <= num; i++)
    {
        fat[i] = tmp[i];
    }
    dfs(cur + 1, x, tnum);
}

auto main() -> int
{
    std::cin >> num >> cnt;
    init(num);
    for (int i = 1; i <= cnt; i++)
    {
        int start;
        int end;
        int value;
        std::cin >> start >> end >> value;
        add(start, end, value);
    }
    std::sort(edge + 1, edge + ecnt + 1, cmp);
    int tot = 0;
    for (int i = 1; i <= ecnt; i++)
    {
        if (edge[i - 1].value != edge[i].value)
        {
            r[pcnt] = i - 1;
            l[++pcnt] = i;
        }
        if (find(edge[i].start) == find(edge[i].end))
        {
            continue;
        }
        merge(edge[i].start, edge[i].end);
        d[pcnt]++;
        tot++;
    }
    r[pcnt] = cnt;
    if (tot != num - 1)
    {
        std::cout << 0;
        return 0;
    }
    init(num);
    for (int i = 1; i <= pcnt; i++)
    {
        sum = 0;
        dfs(l[i], i, 0);
        ans = ans * sum % MOD;
        for (int j = l[i]; j <= r[i]; j++)
        {
            fat[find(edge[j].start)] = find(edge[j].end);
        }
    }
    std::cout << ans;
    return 0;
}
