/*

5
1 4 3 6 5
:5

6
1 1 1 1 1 1
:1

6
2 5 6 6 7 4
:3

6
1 6 5 7 6 6
:5

*/

#include <iostream>
#define N 100001

int arr[N];
int dpo[N];
int dpt[N];

int main()
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    dpt[1] = dpo[1] = 1;
    for (int i = 2; i <= num; i++)
    {
        dpo[i] = dpo[i - 1];
        if ((dpo[i - 1] + 1) % 2 == 0)
        {
            if (arr[i] > arr[i - 1])
            {
                dpo[i]++;
            }
        } else
        {
            if (arr[i] < arr[i - 1])
            {
                dpo[i]++;
            }
        }
        dpt[i] = dpt[i - 1];
        if ((dpt[i - 1] + 1) % 2 == 0)
        {
            if (arr[i] < arr[i - 1])
            {
                dpt[i]++;
            }
        } else
        {
            if (arr[i] > arr[i - 1])
            {
                dpt[i]++;
            }
        }
        // std::cout << dpo[i] << ' ';
    }
    std::cout << std::max(dpt[num], dpo[num]);
    return 0;
}
