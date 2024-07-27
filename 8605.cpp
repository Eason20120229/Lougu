#include <iostream>
#include <vector>
#define N 10001

struct point
{
    std::vector< int > edges;
} points[N];

int ans = 0;
bool vis[N];
int kkk = 0;
int source;

void dfs(int cur, int cnt)
{
    if (cnt > 4)
    {
        ans++;
        return;
    }
    for (int i = 0; i < points[cur].edges.size(); i++)
    {
        int dest = points[cur].edges[i];
        if (!vis[dest] && (dest != source || cnt == 4))
        {
            vis[dest] = true;
            dfs(dest, cnt + 1);
            vis[dest] = false;
        }
    }
}

int main()
{
    int num;
    int cnt;
    std::cin >> num >> cnt;
    while (cnt-- != 0)
    {
        int one;
        int two;
        std::cin >> one >> two;
        points[one].edges.push_back(two);
        points[two].edges.push_back(one);
    }
    for (int i = 1; i <= num; i++)
    {
        source = i;
        dfs(i, 2);
    }
    std::cout << ans;
    return 0;
}
