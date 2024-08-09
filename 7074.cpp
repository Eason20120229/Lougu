/*

time:2h
Time = O(nm)
Space = O(nm)

1.idp[i][j][0] 表示从当前格子的左边走到当前格子能取到的最大整数之和。
2.idp[i][j][1] 表示当前格子的上边走到当前格子能取到的最大整数之和。
3.idp[i][j][2] 表示当前格子的下边走到当前格子能取到的最大整数之和。
3.idp[i][j][3] 表示走到当前格子能取到的最大整数之和。

1.必须要开 long long。
2.当直接递推无法满足无后效性时，可以分类讨论。
3.当递推方向无法同时满足时，可以使用多个循环。

*/

#include <cstdint>
#include <iostream>
#define N   1111
#define INF 0x3f3f3f3f

using std::cin, std::cout, std::max;

int inn;
int inm;
int64_t arr[N][N];
int64_t idp[N][N][4];

int main()
{
    cin >> inn >> inm;
    for (int i = 1; i <= inn; i++)
    {
        for (int j = 1; j <= inm; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 2; i <= inm; i++)
    {
        idp[0][i][3] = idp[0][i][2] = idp[0][i][1] = idp[0][i][0] = -INF;
    }
    for (int i = 2; i <= inm; i++)
    {
        idp[0][i][3] = idp[inn + 1][i][2] = idp[inn + 1][i][1] =
            idp[inn + 1][i][0] = -INF;
    }
    for (int i = 1; i <= inn; i++)
    {
        idp[i][1][3] = idp[i][1][2] = idp[i][1][1] = idp[i][1][0] =
            idp[i - 1][1][0] + arr[i][1];
    }
    for (int j = 2; j <= inm; j++)
    {
        for (int i = 1; i <= inn; i++)
        {
            idp[i][j][0] = idp[i][j - 1][3] + arr[i][j];
            idp[i][j][1] = idp[i - 1][j][3] + arr[i][j];
            idp[i][j][3] = max(idp[i][j][0], idp[i][j][1]);
        }
        for (int i = inn; i > 0; i--)
        {
            idp[i][j][2] = max(idp[i + 1][j][0], idp[i + 1][j][2]) + arr[i][j];
            idp[i][j][3] = max(idp[i][j][3], idp[i][j][2]);
        }
    }
    cout << idp[inn][inm][3];
    return 0;
}
