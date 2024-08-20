#include <iostream>

int main()
{
    long long edge;
    long long len;
    long long width;
    std::cin >> edge >> len >> width;
    if (edge * edge > len * width)
    {
        std::cout << "Alice";
    } else
    {
        std::cout << "Bob";
    }
    return 0;
}
