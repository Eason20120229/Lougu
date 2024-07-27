#include <iostream>
#define N    1000001
#define FOUR 4
#define FIVE 5

auto main() -> int
{
    int num;
    int ans = 0;
    std::cin >> num;
    for (int j = 0; j <= num; j += FIVE)
    {
        if ((num - j) % 4 == 0)
        {
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}
