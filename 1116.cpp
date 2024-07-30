#include <iostream>
#define N 10001

int arr[N];

int main()
{
    int num;
    int ans = 0;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = num - 1; j >= i; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                ans++;
            }
        }
    }
    std::cout << ans;
    return 0;
}
