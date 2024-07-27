#include <algorithm>
#include <iostream>
#define N 30001

int arr[N];

int main()
{
    int maxx;
    int num;
    int ans = 0;
    std::cin >> maxx >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr + 1, arr + num + 1);
    int left = 1;
    int right = num;
    while (left <= right)
    {
        if (arr[left] + arr[right] <= maxx || left == right)
        {
            ans++;
            left++;
            right--;
        } else
        {
            ans++;
            right--;
        }
    }
    std::cout << ans;
    return 0;
}
