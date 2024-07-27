#include <cstring>
#include <iostream>
#define BASE 10
#define N    201
#define MAX  30

int base;

auto is_true(const int inum[]) -> bool
{
    for (int i = 1; i <= inum[0]; i++)
    {
        if (inum[i] != inum[inum[0] - i + 1])
        {
            return false;
        }
    }
    return true;
}

void add(const int one[], const int two[], int three[])
{
    int tmp = 0;
    three[0] = std::max(one[0], two[0]) + 1;
    for (int i = 1; i <= three[0]; i++)
    {
        three[i] = one[i] + two[i] + tmp;
        tmp = three[i] / base;
        three[i] %= base;
    }
    while (three[three[0]] == 0 && three[0] > 1)
    {
        three[0]--;
    }
}

void new_swap(const int one[], int two[])
{
    two[0] = one[0];
    for (int i = 1; i <= one[0]; i++)
    {
        two[one[0] - i + 1] = one[i];
    }
}

auto main() -> int
{
    char num[N];
    int inum[N] = {};
    std::cin >> base >> num;
    inum[0] = static_cast< int >(strlen(num));
    for (int i = 0; i < inum[0]; i++)
    {
        if ('0' <= num[i] && num[i] <= '9')
        {
            inum[inum[0] - i] = num[i] - '0';
        } else if ('A' <= num[i] && num[i] <= 'Z')
        {
            inum[inum[0] - i] = num[i] - 'A' + BASE;
        } else
        {
            inum[inum[0] - i] = num[i] - 'a' + BASE;
        }
    }
    int ans = 0;
    while (!is_true(inum))
    {
        int tmp[N] = {};
        new_swap(inum, tmp);
        add(inum, tmp, inum);
        ans++;
        if (ans > MAX)
        {
            std::cout << "Impossible!";
            return 0;
        }
    }
    std::cout << "STEP=" << ans;
    return 0;
}
