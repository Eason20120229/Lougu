/*

5
4 3 8 2 4
:5

5
2 3 9 4 5
:6

6
2 7 3 9 10 6
:9

6
1 4 2 6 4 9
:6

*/

#include <iostream>
#define N   1000001
#define INF 0x7fffffff

int hei[N];
int dparr[N][2];

int main()
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int tmp;
        std::cin >> hei[i];
    }
    for (int i = 1; i <= num; i++)
    {
        dparr[i][0] = dparr[i][1] = INF;
        for (int j = 1; j <= 2; j++)
        {
            if (j <= i)
            {
                dparr[i][0] = std::min(dparr[i][0], dparr[i - j][1]);
            }
        }
        int jint = i - 1;
        int tmp = std::min(dparr[jint][0], dparr[jint][1]);
        dparr[i][1] = std::min(dparr[i][1], tmp + hei[i]);
    }
    std::cout << std::min(dparr[num][0], dparr[num][1]);
    return 0;
}
