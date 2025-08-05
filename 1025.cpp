#include <iostream>

int num;
int cnt;
int ans;

void dfs(int cur, int nownum, int last)
{
    if (cur == cnt)
    {
        if (nownum == 0)
        {
            ans++;
        }
        return;
    }
    for (int i = last; i <= nownum; i++)
    {
        dfs(cur + 1, nownum - i, i);
    }
}

int main()
{
    std::cin >> num >> cnt;
    dfs(0, num, 1);
    std::cout << ans;
    return 0;
}
