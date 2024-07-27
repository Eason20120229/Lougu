#include <iostream>
#define N 10001

int arr[N];
int sum[N];

int main()
{
    int num;
    int cnt;
    int maxx = 0;
    std::cin >> num >> cnt;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    for (int i = 1; i <= num - cnt; i++)
    {
        maxx = std::max(maxx, sum[cnt + i] - sum[i - 1]);
        // std::cout << maxx << " " << cnt + i << " " << i - 1 << std::endl;
    }
    std::cout << maxx;
    return 0;
}
