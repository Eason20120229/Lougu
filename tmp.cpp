#include <bits/stdc++.h>
using namespace std;
int n, m, a[10000], ans, i = 1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (i <= n)
    {
        while (a[i] <= a[i - 1] && i <= n)
            i++;
        while (a[i] >= a[i - 1] && i <= n)
            i++;
        ans++;
    }
    cout << ans - 2;
    return 0;
}
