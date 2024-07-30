/*

//1 2 1+2 4 1+4 2+4 1+2+4 4+4 1+1+1+2+4 1+1+2+2+4 1+2+2+2+4 2+2+2+2+4
//4+4+4+1 4+4+4+1+1 4+4+4+1+2 4+4+4+4 4+4+4+4+1 4+4+4+4+2
5 3
1 2 4
:18

10 3
1 2 3


*/

#include <algorithm>
#include <iostream>
#define N 201
#define M 2000001

bool dparr[M];
int cur[M];
int arr[N];

bool cmp(int one, int two)
{
    return one > two;
}

int main()
{
    int num;
    int kind;
    int ans;
    std::cin >> num >> kind;
    for (int i = 1; i <= kind; i++)
    {
        scanf("%d", &arr[i]);
    }
    std::sort(arr + 1, arr + 1 + kind, cmp);
    dparr[0] = true;
    cur[0] = 0;
    for (int i = 1;; i++)
    {
        cur[i] = num + 1;
        for (int j = 1; j <= kind; j++)
        {
            if (arr[j] <= i && dparr[i - arr[j]])
            {
                dparr[i] = true;
                cur[i] = std::min(cur[i], cur[i - arr[j]] + 1);
            }
        }
        if (!dparr[i] || cur[i] > num)
        {
            ans = i - 1;
            break;
        }
        // std::cout << dparr[i] << " " << cur[i] << std::endl;
    }
    std::cout << ans;
    return 0;
}
