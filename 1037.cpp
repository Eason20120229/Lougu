#include <iostream>
#include <map>
#include <vector>

using namespace std;

string n;
int k;
int x[21], y[21];
map< int, bool > mp;
vector< int > v[10];
int cnt[1001];
int l1 = 1, l2 = 1;

void f(int i)
{
    if (mp[i])
        return;
    mp[i] = 1;
    cnt[1]++;
    for (int i = 1; i <= l1; i++)
    {
        cnt[i + 1] += cnt[i] / 10;
        cnt[i] %= 10;
    }
    if (cnt[l1 + 1])
        l1++;
    for (int j = 0; j < v[i].size(); j++)
    {
        f(v[i][j]);
    }
}

int main()
{
    int ans[1001] = {0, 1};
    int t[1001] = {};
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x[i] >> y[i];
        v[x[i]].push_back(y[i]);
    }
    int size = n.size();
    for (int i = 0; i < size; i++)
    {
        mp.clear();
        for (int i = 1; i <= max(l1, l2); i++)
        {
            cnt[i] = 0;
            t[i] = ans[i];
            ans[i] = 0;
        }
        f(n[i] - '0');
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                ans[i + j - 1] += cnt[i] * t[j];
                if (ans[i + j - 1] >= 10)
                {
                    ans[i + j] += ans[i + j - 1] / 10;
                    ans[i + j - 1] %= 10;
                }
            }
        }
        int h = l1 + l2 + 1;
        while (ans[h] == 0 && h > 0)
            h--;
        l2 = h;
    }
    for (int i = l2; i >= 1; i--)
    {
        cout << ans[i];
    }
    return 0;
}
