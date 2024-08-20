/*

2 3
:0

3 5
:10

3 4
:6

*/

#include <iostream>
#define N 31

int dparr[N][N];  // dparr[i][j]为第j个人传i次到达第一个人的方案数

int main()
{
    int num;
    int cnt;
    std::cin >> num >> cnt;
    dparr[0][1] = 1;  // 第一个人传0次到达
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            int prev;  // 前一个人
            if (j == 1)
            {
                prev = num;
            } else
            {
                prev = j - 1;
            }
            int next;  // 后一个
            if (j == num)
            {
                next = 1;
            } else
            {
                next = j + 1;
            }
            // 前后都能传过来
            dparr[i][j] = dparr[i - 1][prev] + dparr[i - 1][next];
        }
    }
    std::cout << dparr[cnt][1];
    return 0;
}
