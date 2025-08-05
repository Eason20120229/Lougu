#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[10005];
    int sum = 0;
    double x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    sum -= a[0];
    sum -= a[n - 1];
    x = sum * 1.0 / (n - 2);
    printf("%.2f", x);
    return 0;
}
