#include <iostream>
#include <queue>
#define N 301

using namespace std;

int arr[N];
bool vis[N];

int main()
{
    int num;
    int start;
    int end;
    cin >> num;
    cin >> start >> end;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i];
    }
    queue< pair< int, int > > que;
    que.emplace(start, 0);
    vis[start] = true;
    while (!que.empty())
    {
        pair< int, int > cur = que.front();
        que.pop();
        if (cur.first == end)
        {
            cout << cur.second;
            return 0;
        }
        if (cur.first - arr[cur.first] > 0 && !vis[cur.first - arr[cur.first]])
        {
            vis[cur.first - arr[cur.first]] = true;
            que.emplace(cur.first - arr[cur.first], cur.second + 1);
        }
        if (cur.first + arr[cur.first] <= num &&
            !vis[cur.first + arr[cur.first]])
        {
            vis[cur.first + arr[cur.first]] = true;
            que.emplace(cur.first + arr[cur.first], cur.second + 1);
        }
    }
    cout << -1;
    return 0;
}
