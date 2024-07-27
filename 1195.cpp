#include <bits/stdc++.h>
#define N   1001
#define INF 0x7fffff

int num;
int cnt;
int icnt;
int gcnt = 0;
int fath[N];
int map[N][N];
int group[N];
int minn[N];

int find(int cur)
{
    return (fath[cur] == cur ? cur : find(fath[cur]));
}

void merge(int cur1, int cur2)
{
    cur1 = find(cur1);
    cur2 = find(cur2);
    if (cur1 == cur2)
    {
        return;
    }
    fath[cur1] = fath[cur2];
}

int prim(int start, int inum)
{
    int ans = 0;
    int mini = INF;
    int cur = 0;
    for (int i = 1; i <= num; i++)
    {
        minn[i] = map[start][i];
    }
    for (int i = 1; i < inum; i++)
    {
        mini = INF;
        for (int j = 1; j <= num; j++)
        {
            if (minn[j] != 0 && minn[j] < mini)
            {
                mini = minn[j];
                cur = j;
            }
        }
        if (mini == INF)
        {
            break;
        }
        minn[cur] = 0;
        ans += mini;
        for (int j = 1; j <= num; j++)
        {
            if (minn[j] > map[cur][j])
            {
                minn[j] = map[cur][j];
            }
        }
        std::cout << ans << " ";
    }
    return ans;
}

int main()
{
    std::cin >> num >> cnt >> icnt;
    for (int i = 0; i <= num; i++)
    {
        for (int j = 0; j <= num; j++)
        {
            if (i != j)
            {
                map[i][j] = INF;
            }
        }
    }
    if (num < icnt)
    {
        std::cout << "No Answer";
        return 0;
    }
    for (int i = 1; i <= num; i++)
    {
        fath[i] = i;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int start;
        int end;
        int value;
        std::cin >> start >> end >> value;
        merge(start, end);
        map[start][end] = value;
        map[end][start] = value;
    }
    for (int i = 1; i <= num; i++)
    {
        group[find(fath[i])]++;
    }
    for (int i = 1; i <= num; i++)
    {
        if (group[i] != 0)
        {
            gcnt++;
        }
    }
    if (gcnt > icnt)
    {
        std::cout << "No Answer";
    }
    int ans = 0;
    for (int i = 1; i <= num; i++)
    {
        if (group[i] != 0)
        {
            ans += prim(i, group[i]);
        }
        // std::cout << ans << std::endl;
        // std::cout << i << std::endl;
    }
    std::cout << ans;
    return 0;
}
