#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
queue< int > q;
vector< int > G[N];
vector< int > ans;  // 存放拓扑序列
int in[N];
bool bfs_topsort(int n)  // n为节点个数
{
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);  // 将入度为0的点入队列
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();  // 选一个入度为 0 的点，出队
        ans.push_back(u);
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            in[v]--;
            if (in[v] == 0)
            {
                // 当某一条边的入度为0，入队
                q.push(v);
            }
        }
    }
    if (ans.size() == n)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            // 输出答案
            cout << ans[i] << " ";
        }
        return true;
    }
    return false;  // 图内还有剩余节点，存在环路
}

int main()
{
    int n;
    int m;
    int a;
    int b;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }
    if (!bfs_topsort(n))
    {
        cout << "No answer";
    }
    cout << endl;
    return 0;
}
