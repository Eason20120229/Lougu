#include <bits/stdc++.h>
#define N 2000000

int main()
{
    int num;
    std::array< bool, N + 1 > arr{};
    std::cin >> num;
    for (int k = 1; k <= num; k++)
    {
        double val;
        int cnt;
        std::cin >> val >> cnt;
        for (int i = 1; i <= cnt; i++)
        {
            arr[floor(val * i)] = !arr[floor(val * i)];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (arr[i])
        {
            std::cout << i;
            return 0;
        }
    }
    return 0;
}
