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

int dparr[N][N];

int main()
{
    int num;
    int cnt;
    std::cin >> num >> cnt;
    dparr[0][1] = 1;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            int prev;
            if (j == 1)
            {
                prev = num;
            } else
            {
                prev = j - 1;
            }
            int next;
            if (j == num)
            {
                next = 1;
            } else
            {
                next = j + 1;
            }
            dparr[i][j] = dparr[i - 1][prev] + dparr[i - 1][next];
            // std::cout << dparr[i][j] << " ";
        }
        // std::cout << std::endl;
    }
    std::cout << dparr[cnt][1];
    return 0;
}
