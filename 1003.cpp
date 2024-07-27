#include <iostream>

using namespace std;

int input[10001][4], x, y;

int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int a, b, g, k;
        cin >> a >> b >> g >> k;
        input[i][0] = a;
        input[i][1] = b;
        input[i][2] = g + a - 1;
        input[i][3] = k + b - 1;
        i++;
    }
    int ans = -1;
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        if (input[i][0] <= x && input[i][1] <= y && input[i][2] >= x &&
            input[i][3] >= y)
        {
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
