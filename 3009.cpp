#include <iostream>
#define N   100001
#define INF 1001

int arr[N];
int dparr[N];

int main()
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    int ans = -INF;
    for (int i = 1; i <= num; i++)
    {
        bool flag = true;
        if (dparr[i - 1] + arr[i] < 0)
        {
            flag = false;
        } else
        {
            dparr[i] = dparr[i - 1] + arr[i];
        }
        if (flag)
        {
            ans = std::max(ans, dparr[i]);
        } else
        {
            ans = std::max(ans, arr[i]);
        }
    }
    std::cout << ans;
    return 0;
}
