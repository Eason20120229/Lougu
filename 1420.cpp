#include <iostream>
#define N 10001

int arr[N];

int main()
{
    int num;
    int ans = 1;
    int tmp = 1;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 2; i <= num; i++)
    {
        ans = std::max(ans, tmp);
        if (arr[i] - 1 == arr[i - 1])
        {
            tmp++;
        } else
        {
            tmp = 1;
        }
    }
    ans = std::max(ans, tmp);
    std::cout << ans;
    return 0;
}
