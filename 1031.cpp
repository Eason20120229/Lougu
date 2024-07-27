#include <iostream>

using namespace std;

int a[101];

auto main() -> int
{
    int n;
    int ans = 0;
    cin >> n;
    int li = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        li += a[i];
    }
    li /= n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != li)
        {
            ans++;
        }
        a[i + 1] += a[i] - li;
        a[i] = li;
    }
    cout << ans;
    return 0;
}
