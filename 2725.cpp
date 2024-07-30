/*

//1 2 1+2 4 1+4 2+4 1+2+4 1+1+2+4 1+1+1+2+4 1+1+2+2+4 1+2+2+2+4 2+2+2+2+4
//4+4+4+1 4+4+4+1+1 4+4+4+1+2 4+4+4+4 4+4+4+4+1 4+4+4+4+2
5 3
1 2 4
:18

*/

#include <iostream>
#define N 201

bool dparr[N][N];
int arr[N];

int main()
{
    int num;
    int kind;
    int ans;
    std::cin >> num >> kind;
    for (int i = 1; i <= kind; i++)
    {
        std::cin >> arr[i];
    }
    dparr[0][0] = true;
    for (int i = 1;; i++)
    {
        bool flag = false;
        for (int j = 1; j <= num; j++)
        {
            for (int k = 1; k <= kind; k++)
            {
                if (i >= arr[k])
                {
                    dparr[i][j] |= dparr[i - arr[k]][j - 1];
                }
            }
        }
        for (int j = 1; j <= num; j++)
        {
            flag |= dparr[i][j];
        }
        if (!flag)
        {
            ans = i - 1;
            break;
        }
    }
    std::cout << ans;
    return 0;
}
