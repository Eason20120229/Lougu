#include <cstdint>
#include <iostream>

int main()
{
    int test;
    std::cin >> test;
    while (test-- != 0)
    {
        int64_t num;
        int64_t ans = 0;
        std::cin >> num;
        while (num != 0)
        {
            if (num % 2 == 1)
            {
                ans++;
                if ((num - 1) / 2 % 2 == 0)
                {
                    num = (num - 1) / 2;
                }
                if ((num + 1) / 2 % 2 == 0)
                {
                    num = (num + 1) / 2;
                }
            } else
            {
                num /= 2;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
