#include <iomanip>
#include <iostream>
#define N 101
#define V 100

int arr[N];
double dparr[N];
bool dpr[N];

auto main() -> int
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    dparr[0] = V;
    double ans = 0;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            double tmp;
            double tmp2;
            if (!dpr[i])
            {
                tmp2 = dparr[i];
            } else
            {
                tmp2 = dparr[i] / arr[i];
            }
            if (!dpr[j])
            {
                tmp = dparr[j] * arr[i];
                if (dparr[j] > tmp2)
                {
                    dparr[i] = tmp;
                    dpr[i] = true;
                }
            } else
            {
                tmp = dparr[j] / arr[i];
                if (tmp > tmp2)
                {
                    dparr[i] = tmp;
                    dpr[i] = false;
                }
            }
        }
        if (!dpr[i])
        {
            ans = std::max(ans, dparr[i]);
        } else
        {
            ans = std::max(ans, dparr[i] / arr[i]);
        }
    }
    std::cout << std::fixed << std::setprecision(2) << ans;
    return 0;
}
