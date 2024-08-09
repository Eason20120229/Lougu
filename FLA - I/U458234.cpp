#include <algorithm>
#include <iostream>

using namespace std;

int arr[200001];

int main()
{
    int n;
    int m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i < n; i++)
    {
        ans += min(m, arr[i + 1] - arr[i]);
    }
    cout << ans + m;
    return 0;
}
