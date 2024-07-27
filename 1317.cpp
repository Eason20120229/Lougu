#include <iostream>
#include <vector>
#define N 100001

auto main() -> int
{
    int num = 0;
    int ans = 0;
    std::vector< int > arr;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (i == 1 || tmp > arr[arr.size() - 1])
        {
            arr.push_back(tmp);
        }
    }
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i - 1] > arr[i] && arr[i + 1] > arr[i])
        {
            ans++;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << ans;
    return 0;
}
