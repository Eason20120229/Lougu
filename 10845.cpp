#include <iostream>
#include <vector>
#define N         200005
#define lowbit(x) ((-x) & x)

using std::cin, std::cout, std::max, std::vector;

struct node
{
    int l, r;
};

int num;
int dparr[N];
node input[N];          // 输入
int tree[N];            // 树状数组
vector< int > save[N];  // 记录进入树状数组的dp[j]

void update(int value, int rnode)  // 更新 rnode 位置的值为和 value 的最大值
{
    for (int i = rnode; i <= num; i += lowbit(i))
    {
        tree[i] = max(tree[i], value);
    }
}

int getm(int rnode)  // 获取[1,rnode] 区间中的最大值
{
    int ans = 0;
    for (int i = rnode; i > 0; i -= lowbit(i))
    {
        ans = max(tree[i], ans);
    }
    return ans;
}

int main()
{
    int ans = 0;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int tml;
        int tmr;
        cin >> tml >> tmr;
        // 转换为全局单位
        input[i].l = i - tml;
        if (input[i].l < 1)
        {
            input[i].l = 1;
        }
        input[i].r = i + tmr;
        if (input[i].r > num)
        {
            input[i].r = num;
        }
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < save[i].size(); j++)  // 进入树状数组
        {
            update(dparr[save[i][j]], save[i][j]);
        }
        dparr[i] = getm(input[i].l - 1) + 1;
        save[input[i].r + 1].push_back(i);
        ans = max(ans, dparr[i]);
    }
    cout << ans;
    return 0;
}
