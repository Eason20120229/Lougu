#include <bits/stdc++.h>
using namespace std;

int a[10001];

int main()
{
    int l, m;
    cin >> l >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        for (int i = u; i <= v; i++)
        {
            a[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= l; i++)
    {
        if (!a[i])
            ans++;
    }
    cout << ans;
    return 0;
}
