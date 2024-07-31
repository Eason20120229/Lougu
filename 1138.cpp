#include <algorithm>
#include <iostream>
#define N 100001

int arr[N];

int main()
{
    int num;
    int thi;
    std::cin >> num >> thi;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr + 1, arr + 1 + num);
    int cur = 0;
    for (int i = 1; i <= num; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            cur++;
            if (cur == thi)
            {
                std::cout << arr[i];
                return 0;
            }
        }
    }
    std::cout << "NO RESULT";
    return 0;
}
