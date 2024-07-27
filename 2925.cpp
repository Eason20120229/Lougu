#include <array>
#include <iostream>
#define N 50001

std::array< int, N > dparr;
std::array< int, N > arr;

auto main() -> int
{
    int num;
    int vec;
    std::cin >> vec >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = vec; j > 0; j--)
        {
            if (j >= arr[i])
            {
                dparr[j] = std::max(dparr[j], dparr[j - arr[i]] + arr[i]);
            }
        }
    }
    std::cout << dparr[vec];
    return 0;
}
