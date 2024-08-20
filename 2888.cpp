#include <iostream>
#define N   301
#define INF 0x3fffffff

using namespace std;

int graph[N][N];

int main()
{
    int num;
    int cnt;
    int test;
    cin >> num >> cnt >> test;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (i != j)
            {
                graph[i][j] = INF;
            }
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        int start;
        int end;
        int high;
        cin >> start >> end >> high;
        graph[start][end] = high;
    }
    for (int k = 1; k <= num; k++)
    {
        for (int i = 1; i <= num; i++)
        {
            for (int j = 1; j <= num; j++)
            {
                graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
            }
        }
    }
    for (int i = 1; i <= test; i++)
    {
        int start;
        int end;
        cin >> start >> end;
        if (graph[start][end] == INF)
        {
            cout << -1 << endl;
        } else
        {
            cout << graph[start][end] << endl;
        }
    }
    return 0;
}
