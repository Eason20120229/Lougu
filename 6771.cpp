#include <algorithm>
#include <iostream>
#define N 4001
using std::ios, std::cin, std::cout, std::sort;

struct block
{
    int hei;
    int maxh;
    auto operator<(const block &blk) const -> bool
    {
        return this->maxh < blk.maxh;
    }
};

int num;
block arr[N];
int dparr[N];

int main()
{
    ios::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);
    int tot = 0;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int thei;
        int tmh;
        int tnum;
        cin >> thei >> tmh >> tnum;
        for (int j = 1; j <= tnum; j++)
        {
            arr[++tot] = {thei, tmh};
        }
    }
    num = tot;
    sort(arr + 1, arr + 1 + num);
    return 0;
}
