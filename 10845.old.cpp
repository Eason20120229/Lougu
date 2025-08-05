#include <iostream>
#define N         200001
#define lowbit(x) ((-x) & x)

using std::cin, std::cout, std::max;

struct node
{
    int l, r;
};

int num;
int dparr[N];    // dp 数组
node input[N];   // 输入
int tree[N][N];  // 树状数组

// 更新 (right,rnode) 位置的值为原值和 value 的最大值
void update(int value, int right, int rnode)
{
    for (int i = right; i <= num; i += lowbit(i))
    {
        for (int j = rnode; j <= num; j += lowbit(j))
        {
            tree[i][j] = max(tree[i][j], value);
        }
    }
}

int getm(int right, int rnode)  // 获取[(1,1),(right,rnode)] 区间中的最大值
{
    int ans = 0;
    for (int i = right; i > 0; i -= lowbit(i))
    {
        for (int j = rnode; j > 0; j -= lowbit(j))
        {
            ans = max(tree[i][j], ans);
        }
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
        dparr[i] = getm(i - 1, input[i].l - 1) + 1;
        update(dparr[i], input[i].r, i);  // 更新
        ans = max(ans, dparr[i]);         // 取最大值
    }
    cout << ans;
    return 0;
}
