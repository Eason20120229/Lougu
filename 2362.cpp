/*

5
2 5 3 8 9
:4 2

20
1 4 2 7 34 8 3 76 3 8 5 8 34 86 67 2 90 4 78 28 76
:9 12

5
1 67 3 9 5
:3 2

5
2 7 3 9 5
:3 3

5
1 4 3 7 4
:3 4

*/

#include <bits/stdc++.h>
#define N 21

namespace run
{
    int num;
    int arr[N];
    int dparr[N];
    int count[N];

    void init()
    {
        std::cin >> num;
        for (int i = 1; i <= num; i++)
        {
            std::cin >> arr[i];
            dparr[i] = 0;
        }
    }
    void print(int length, int amount)
    {
        std::cout << length << " " << amount << std::endl;
    }
    void solve()
    {
        int length = 1;
        int amount = 1;
        init();
        for (int i = 1; i <= num; i++)
        {
            count[i] = 1;
            dparr[i] = 1;
            for (int j = 1; j < i; j++)
            {
                if (arr[j] <= arr[i])
                {
                    if (dparr[i] == dparr[j] + 1)
                    {
                        count[i] += count[j];
                    } else if (dparr[i] < dparr[j] + 1)
                    {
                        count[i] = count[j];
                        dparr[i] = dparr[j] + 1;
                    }
                }
            }
            if (dparr[i] > length)
            {
                length = dparr[i];
                amount = count[i];
            } else if (dparr[i] == length)
            {
                amount += count[i];
            }
        }
        print(length, amount);
    }
}  // namespace run

int main()
{
    int cnt;
    std::cin >> cnt;
    while (cnt-- != 0)
    {
        run::solve();
    }
    return 0;
}
