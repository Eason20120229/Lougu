#include <iostream>
#define N 100001

int arr[N];

int main()
{
    int num;
    int maxn;
    std::cin >> num >> maxn;
    for (int i = 1; i <= num; i++)
    {
        int tmp;
        std::cin >> tmp;
        arr[i] = arr[i - 1] + tmp;
    }
    int start = 1;
    int end = 1;
    int ans = 0;
    while (end <= num)
    {
        // std::cout << start << " " << end;
        if (arr[end] - arr[start - 1] > maxn)
        {
            ans++;
            start = end;
        } else
        {
            end++;
        }
        // std::cout << "-" << ans << "\n";
    }
    ans++;
    std::cout << ans;
    return 0;
}
