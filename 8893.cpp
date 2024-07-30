#include <iostream>
#include <queue>
#define N 5001

struct node
{
    int id;
    int day;
};

bool arr[N];
bool sale[N];
int inner[N];
int graph[N][N];
std::queue< node > que;

auto main() -> int
{
    int num;
    int cur;
    int cnt;
    int rule;
    std::cin >> num >> cur >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp] = true;
        if (tmp == cur)
        {
            std::cout << 0;
            return 0;
        }
    }
    std::cin >> rule;
    while (rule-- != 0)
    {
        int end;
        int ecnt;
        scanf("%d %d", &end, &ecnt);
        while (ecnt-- != 0)
        {
            int start;
            scanf("%d", &start);
            if (!arr[start] && !arr[end])
            {
                if (graph[start][end] == 0)
                {
                    inner[end]++;
                }
                graph[start][end] = 1;
            }
        }
        sale[end] = true;
    }
    for (int i = 1; i <= num; i++)
    {
        if (inner[i] == 0 && !arr[i] && sale[i])
        {
            que.push({i, 1});
        }
        // std::cout << inner[i] << " ";
    }
    while (!que.empty())
    {
        node tmp = que.front();
        que.pop();
        // std::cout << tmp.day << " " << tmp.id << std::endl;
        if (tmp.id == cur)
        {
            std::cout << tmp.day;
            return 0;
        }
        for (int i = 1; i <= num; i++)
        {
            if (graph[tmp.id][i] == 1)
            {
                graph[tmp.id][i] = 0;
                inner[i]--;
            }
            if (inner[i] == 0 && !arr[i] && sale[i])
            {
                que.push({i, tmp.day + 1});
                arr[i] = true;
            }
        }
    }
    std::cout << -1;
    return 0;
}
