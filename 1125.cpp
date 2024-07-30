#include <cstring>
#include <iostream>
#define N 26
#define M 100

int arr[N];

bool check(int num)
{
    if (num == 1 || num == 0)
    {
        return false;
    }
    for (int i = 3; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[M + 1];
    std::cin >> str;
    for (int i = 0; i < strlen(str); i++)
    {
        arr[str[i] - 'a']++;
    }
    int maxn = 0;
    int minn = M;
    for (int i = 0; i < N; i++)
    {
        maxn = std::max(maxn, arr[i]);
        if (arr[i] != 0)
        {
            minn = std::min(minn, arr[i]);
        }
    }
    if (check(maxn - minn))
    {
        std::cout << "Lucky Word\n" << maxn - minn;
    } else
    {
        std::cout << "No Answer\n0";
    }
    return 0;
}
