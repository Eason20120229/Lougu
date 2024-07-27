#include <iostream>
#define N 1001

int arr[N];
int cnt;

int main()
{
    long long ans = 0;
    int base;
    int num;
    std::cin >> base >> num;
    while (num > 0)
    {
        arr[++cnt] = num % 2;
        num /= 2;
    }
    for (int i = cnt; i >= 1; i--)
    {
        ans = ans * base + arr[i];
    }
    std::cout << ans;
    return 0;
}
