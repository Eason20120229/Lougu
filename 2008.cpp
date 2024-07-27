#include <iostream>
#define N 10001

struct node
{
    int len;
    int ans;
} dpr[N];

int arr[N];

int main()
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 1; i <= num; i++)
    {
        dpr[i].len = 1;
        dpr[i].ans = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] <= arr[i] && dpr[j].len + 1 > dpr[i].len)
            {
                dpr[i].len = dpr[j].len + 1;
                dpr[i].ans = dpr[j].ans + arr[i];
            }
        }
    }
    for (int i = 1; i <= num; i++)
    {
        std::cout << dpr[i].ans << " ";
    }
    return 0;
}
