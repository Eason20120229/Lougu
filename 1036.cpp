#include <bits/stdc++.h>
#define N   21
#define NUM 10000001

using namespace std;

int num;
int i_k;
array< int, N > arr;
int pri[NUM];
bool isp[NUM];
bool vis[N];
int ans = 0;
int sum = 0;

void euler()
{
    int cnt = 0;
    isp[0] = true;
    isp[1] = true;
    for (int i = 2; i <= NUM - 1; i++)
    {
        if (!isp[i])
        {
            pri[++cnt] = i;
            // cout << pri[cnt] << " ";
        }
        for (int j = 1; j <= cnt; j++)
        {
            if (pri[j] * i >= NUM)
            {
                break;
            }
            isp[pri[j] * i] = true;
            if (i % pri[j] == 0)
            {
                break;
            }
        }
    }
    // cout << endl;
}

void dfs(int i, int last)
{
    if (i == i_k)
    {
        if (!isp[sum])
        {
            ans++;
        }
        return;
    }
    for (int j = last + 1; j <= num; j++)
    {
        if (!vis[j])
        {
            vis[j] = true;
            sum += arr[j];
            dfs(i + 1, j);
            vis[j] = false;
            sum -= arr[j];
        }
    }
}

auto main() -> int
{
    cin >> num >> i_k;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i];
    }
    euler();
    dfs(0, 0);
    cout << ans;
    return 0;
}
