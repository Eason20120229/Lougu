#include <iostream>

using namespace std;

int a, b, c, d;
int g[4];

int go(int a, int b, int c)
{
    switch (c)
    {
    case 1: return a + b;
    case 2: return a - b;
    case 3: return a * b;
    }
    return 0;
}

bool dfs(int i)
{
    if (i == 2)
    {
        int tmp = 0;
        tmp = go(a, b, g[0]);
        tmp = go(tmp, c, g[1]);
        return tmp == d;
    }
    for (int j = 1; j <= 3; j++)
    {
        g[i] = j;
        if (dfs(i + 1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> a >> b >> c >> d;
    if (dfs(0))
    {
        cout << "Yes";
    } else
    {
        cout << "No";
    }
    return 0;
}
