#include <iostream>
#define N 501
#define M 45001

int arr[N];
int dparr[M];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int eat;
    int num;
    std::cin >> eat >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = eat; j > 0; j--)
        {
            if (arr[i] <= j)
            {
                dparr[j] = std::max(dparr[j], dparr[j - arr[i]] + arr[i]);
            }
        }
    }
    std::cout << dparr[eat];
    return 0;
}
