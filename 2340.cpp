#include <array>
#include <iostream>
#define N 401

struct cow
{
    int s;
    int f;
    int sum;
};

std::array< int, N > arrs;
std::array< int, N > arrf;
std::array< std::array< cow, 2 >, N > dparr;

auto main() -> int
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arrs[i] >> arrf[i];
    }
    for (int i = 1; i <= num; i++)
    {
        cow last;
        if (dparr[i - 1][0].sum > dparr[i - 1][1].sum)
        {
            last = dparr[i - 1][0];
        } else
        {
            last = dparr[i - 1][1];
        }
        cow tmp = {last.s + arrs[i], last.f + arrf[i]};
        tmp.sum = tmp.s + tmp.f;
        if (tmp.sum >= last.sum)
        {
            dparr[i][1] = tmp;
        } else
        {
            dparr[i][1] = last;
        }
        dparr[i][0] = last;
        std::cout << dparr[i][0].sum << " " << dparr[i][1].sum << " "
                  << last.sum << std::endl;
    }
    int ans;
    if (dparr[num][0].s < 0)
    {
        ans = dparr[num][1].sum;
    } else if (dparr[num][1].s < 0)
    {
        ans = dparr[num][0].sum;
    } else
    {
        ans = std::max(dparr[num][0].sum, dparr[num][1].sum);
    }
    std::cout << ans;
    return 0;
}
// tmp.s >= 0 && tmp.f >= 0
