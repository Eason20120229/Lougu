#include <bits/stdc++.h>
using namespace std;

int ans;
int a[10];
int book[10];

int shu(int i)
{
    return a[i] * 100 + a[i + 1] * 10 + a[i + 2];
}

void dfs(int n)
{
    if (n == 10)
    {
        if (shu(1) == shu(4) / 2 && shu(7) / 3 == shu(1))
        {
            cout << shu(1) << " " << shu(4) << " " << shu(7) << endl;
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!book[i])
        {
            book[i] = 1;
            a[n] = i;
            dfs(n + 1);
            book[i] = 0;
        }
    }
}

int main()
{
    dfs(1);
    return 0;
}
