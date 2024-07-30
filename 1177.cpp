#include <bits/stdc++.h>
using namespace std;

int a[100001];
int n;

void qsort(int l, int r)
{
    int i = l, j = r, f = a[(l + r) / 2];
    do
    {
        while (a[i] < f)
            i++;
        while (a[j] > f)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    while (i <= j);
    if (l < j)
        qsort(l, j);
    if (i < r)
        qsort(i, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qsort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
