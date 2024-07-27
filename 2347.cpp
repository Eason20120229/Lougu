/*
1 2 3 5 10 20

1 1 1 0 0 0
:6

1 2 1 0 0 0
:8

1 0 1 0 0 1
:7

1 0 0 1 0 1
:7

1 0 0 2 0 0
:5

*/

#include <iostream>
#define N  1005
#define IN 7
#define G                     \
    {                         \
        0, 1, 2, 3, 5, 10, 20 \
    }

int cnt;
int arr[N];
int arr6[IN] = G;
bool dparr[N][N];

int main()
{
    int maxn = 0;
    for (int i = 1; i < IN; i++)
    {
        int tmp;
        std::cin >> tmp;
        maxn += tmp * arr6[i];
        while (tmp-- != 0)
        {
            arr[++cnt] = arr6[i];
        }
    }
    for (int i = 0; i <= cnt; i++)
    {
        dparr[i][0] = true;
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= maxn; j++)
        {
            dparr[i][j] = dparr[i - 1][j];
            if (j >= arr[i])
            {
                dparr[i][j] |= dparr[i - 1][j - arr[i]];
            }
            // std::cout << dparr[i][j] << " ";
        }
        // std::cout << "\n";
    }
    int ans = 0;
    for (int i = 1; i <= maxn; i++)
    {
        if (dparr[cnt][i])
        {
            ans++;
        }
    }
    std::cout << "Total=" << ans;
    return 0;
}
