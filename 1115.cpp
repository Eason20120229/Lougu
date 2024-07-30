#include <bits/stdc++.h>
using namespace std;

int ans, *a;

int main()
{
    int n;
    cin >> n;
    a = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        t += a[i];
        if (t < -1)
        {
            t = 0;
        }
        ans = max(ans, t);
    }
    if (ans == 0)
    {
        ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans = max(ans, a[i]);
        }
    }
    cout << ans;
    return 0;
}
