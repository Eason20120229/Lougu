#include <iostream>
#define N 10001
#define M 100001

struct edg
{
    int id;
    int next;
};

int ecnt;
int head[N];
edg edge[M];
bool vis[N];
bool pcol[N];
int black;
int white;

void init(int num, int cnt)
{
    for (int i = 1; i <= num; i++)
    {
        head[i] = -1;
    }
    for (int i = 1; i <= cnt; i++)
    {
        edge[i].next = -1;
    }
}

void add(int start, int end)
{
    int idt = ++ecnt;
    edge[idt].id = end;
    edge[idt].next = head[start];
    head[start] = end;
}

bool dfs(int idt, bool color)
{
    if (vis[idt])
    {
        return pcol[idt] == color;
    }
    vis[idt] = true;
    pcol[idt] = color;
    color ? black++ : white++;
    bool flag = true;
    for (int i = head[idt]; i != -1 && flag; i = edge[i].next)
    {
        flag = flag && dfs(i, !color);
    }
    return flag;
}

auto main() -> int
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int num;
    int cnt;
    int ans = 0;
    std::cin >> num >> cnt;
    init(num, cnt);
    while (cnt-- != 0)
    {
        int start;
        int end;
        std::cin >> start >> end;
        add(start, end);
        std::swap(start, end);
        add(start, end);
    }
    for (int i = 1; i <= num; i++)
    {
        if (!vis[i])
        {
            if (!dfs(i, false))
            {
                std::cout << "Impossible";
                return 0;
            }
        }
        ans += std::min(white, black);
        white = 0;
        black = 0;
    }
    std::cout << ans;
    return 0;
}
