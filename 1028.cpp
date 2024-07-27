#include <iostream>
#define N 1001

int idp[N];

int dfs(int num)
{
    if (idp[num] != 0)
    {
        return idp[num];
    }
    int ans = 1;
    for (int i = 1; i <= num / 2; i++)
    {
        ans += dfs(i);
    }
    idp[num] = ans;
    return ans;
}

int main()
{
    int num;
    std::cin >> num;
    std::cout << dfs(num);
    return 0;
}
