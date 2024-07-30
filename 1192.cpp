#include <cstdint>
#include <iostream>
#define N   100001
#define MOD 100003

int64_t dparr[N];

int main()
{
    int num;
    int step;
    std::cin >> num >> step;
    dparr[0] = 1;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= step; j++)
        {
            if (i - j >= 0)
            {
                dparr[i] += dparr[i - j];
                dparr[i] %= MOD;
            }
        }
    }
    std::cout << dparr[num];
    return 0;
}
