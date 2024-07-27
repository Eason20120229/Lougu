#include <iostream>
#define N 100001

int num;
int arr[N];

int calc(int len)
{
    int ans = 0;
    for (int i = 1; i <= num; i++)
    {
        ans += arr[i] / len;
    }
    return ans;
}

int main()
{
    int maxx = 0;
    int dest;
    std::cin >> num >> dest;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
        maxx = std::max(maxx, arr[i]);
    }
    int left = 0;
    int right = maxx;
    while (left < right)
    {
        int mid = ((left + right) >> 1) + 1;
        if (calc(mid) < dest)
        {
            right = mid - 1;
        } else
        {
            left = mid;
        }
    }
    std::cout << right;
    return 0;
}
