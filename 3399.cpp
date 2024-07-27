/*

3 5
10
25
15
50
30
15
40
30
:1125

2 3
10
11
4
8
5
:95

*/

#include <iostream>
#include <array>
#define N 1001
#define INF 0x7fffffff

std::array< int, N > arrd;
std::array< int, N > arrc;
std::array< std::array< int, N >, N > dparr;

auto main() -> int
{
    int cnt;
    int num;
    std::cin >> cnt >> num;
    for(int i = 1;i <= cnt;i++)
    {
        std::cin >> arrd[i];
    }
    for(int i = 1;i <= num;i++)
    {
        std::cin >> arrc[i];
    }
    for(int i = 1;i <= cnt;i++)
    {
        for(int j = i;j <= num - cnt + i;j++)
        {
            dparr[i][j] = INF;
            for(int k = i - 1;k <= j - 1;k++)
            {
                dparr[i][j] = std::min(dparr[i - 1][k] + arrd[i] * arrc[j],dparr[i][j]);
            }
            // std::cout << dparr[i][j] << " " << i << " " << j << std::endl;
        }
    }
    int ans = INF;
    for(int j = cnt;j <= num;j++)
    {
        ans = std::min(ans, dparr[cnt][j]);
    }
    std::cout << ans;
    return 0;
}
