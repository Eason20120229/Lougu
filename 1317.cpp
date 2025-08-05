#include <array>
#include <iostream>
#define N 100001

auto main() -> int
{
    int num = 0;
    int ans = 0;
    std::array< int, N > arr;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    int cur = 2;
    while (cur < num)
    {
        bool flag = false;
        bool flag2 = false;
        while (cur < num && arr[cur] >= arr[cur + 1])
        {
            cur++;
            flag = true;
        }
        while (cur < num && arr[cur] <= arr[cur + 1])
        {
            cur++;
            flag2 = true;
        }
        if (cur < num && flag && flag2)
        {
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}
