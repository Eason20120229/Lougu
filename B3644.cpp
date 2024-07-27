#include <iostream>
#define N 101

int gra[N][N];
int vis[N];
int ans[N];
int cnt = 0;
int num;

void dfs(int cur)
{
    vis[cur] = 1;
    for (int i = 1; i <= num; i++)
    {
        if (gra[cur][i] != 0 && vis[i] == 0)
        {
            dfs(i);
        }
    }
    ans[++cnt] = cur;
    vis[cur] = -1;
}

int main()
{
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        while (true)
        {
            int dest;
            std::cin >> dest;
            if (dest == 0)
            {
                break;
            }
            gra[i][dest] = 1;
        }
    }
    for (int i = 1; i <= num; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }
    for (int i = cnt; i > 0; i--)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}
