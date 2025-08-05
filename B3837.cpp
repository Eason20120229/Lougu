#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, b = 'A';
    char a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a = b, cout << a, b++;
            if (b == 'Z' + 1)
                b = 'A';
        }
        cout << endl;
    }
    return 0;
}
