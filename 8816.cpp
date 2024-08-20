/*

time:1.5h
Time = O(kn^2)
Space = O(n^2)

一、解题思路
1.将点按x轴排序，y轴方向即可用最长不下降子序列的方法解决。
2.由于可以添加点，所以可以在原本的线性dp里使用背包dp。

*/

#include <algorithm>
#include <cstring>
#include <iostream>
#define N 501

using std::cin, std::cout, std::sort;

struct point
{
    int x, y;
} arr[N];

int num;
int cnt;
int idp[N][N];
int dis[N][N];
bool flag[N];

bool cmp(point one, point two)
{
    if (one.x == two.x)
    {
        return one.y < two.y;
    }
    return one.x < two.x;
}

void init()
{
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr + 1, arr + num + 1, cmp);
    for (int i = 1; i <= num; i++)
    {
        for (int j = i + 1; j <= num; j++)
        {
            if (arr[i].y <= arr[j].y)  // 如果单调
            {
                // 计算距离
                dis[i][j] = (arr[j].x - arr[i].x) + (arr[j].y - arr[i].y) - 1;
            }
        }
    }
}

int main()
{
    cin >> num >> cnt;
    init();
    int ans = 0;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].y <= arr[i].y)  // 如果单调
            {
                for (int k = 0; k <= cnt; k++)
                {
                    if (k >= dis[j][i])  // 如果可以添加
                    {
                        idp[i][k] =
                            std::max(idp[i][k], idp[j][k - dis[j][i]] + 1);
                    }
                }
            }
        }
        ans = std::max(ans, idp[i][cnt]);
    }
    cout << ans + cnt;
    return 0;
}
