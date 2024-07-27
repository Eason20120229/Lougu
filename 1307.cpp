#include <cstdint>
#include <cstring>
#include <iostream>
#define N 101

auto main() -> int
{
    char num[N] = {};
    int len;
    std::cin >> num;
    len = static_cast< int >(strlen(num));
    if (num[0] == '-')
    {
        num[0] = 0;
        std::cout << "-";
    }
    while (num[len - 1] == '0' && len > 1)
    {
        num[--len] = 0;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        std::cout << num[i];
    }
    return 0;
}
