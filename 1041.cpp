#include <future>
#include <iostream>

bool check(long long i, long long j)
{
    return i * j > 2147483647 || i * j < -2147483648;
}

auto main() -> int
{
    long long x1, x2, y1, y2;
    std::cin >> x1 >> x2 >> y1 >> y2;
    if (check(x1, y1) || check(x1, y2) || check(x2, y1) || check(x2, y2))
    {
        std::cout << "long long int";
    } else
    {
        std::cout << "int";
    }
    return 0;
}
