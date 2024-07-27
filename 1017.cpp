#include <cmath>
#include <iostream>
#define BASE 10
#define N    10000001

int cnt = 0;
char ans[N];

void print(int inum)
{
    if (inum < BASE)
    {
        ans[++cnt] = static_cast< char >(inum + '0');
    } else
    {
        ans[++cnt] = static_cast< char >('A' + inum - BASE);
    }
}

auto main() -> int
{
    int shu;
    int num;
    int base;
    std::cin >> shu >> base;
    num = shu;
    while (num != 0)
    {
        int tmp = num / base;
        int modl = num - tmp * base;
        while (modl < 0)
        {
            tmp++;
            modl = num - tmp * base;
        }
        print(modl);
        num = tmp;
        // std::cout << " " << num << std::endl;
    }
    std::cout << shu << "=";
    for(int i = cnt;i > 0;i--)
    {
        std::cout << ans[i];
    }
    std::cout << "(base" << base << ")";
    return 0;
}
