// 题目 NOI 2017 Day2 T2
// 洛谷 P3826
// 知识点应用：可以用高阶的 网络流 费用流 建模
// 也可以只用最简单的：堆/优先队列+并查集
// 大家日常学习 要多看几篇题解

#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

struct Node {   // 优先队列按 单价 大根堆
    int cnt;    // 当前件数
    int full;   // 总库存
    int delta;  // 每天过期多少件
    int val;    // 单价
};

const int N = 1e5, M = 1e6 + 7;
int root[N + 7], cnt[N + 7];
ll ans[M];
priority_queue< Node > q;

bool operator<(const Node a, const Node b) {
    return a.val < b.val;  // 价格贵得 大根堆
}

void init(int m) {
    for (int i = 1; i <= N; i++) {
        // 日期 根节点
        root[i] = i;  // 并查集初始化
        cnt[i] = m;   // 每天卖 m 个
    }
}

int get_root(int x) {  // 并查集 查
    if (root[x] == x) {
        return x;
    }
    return root[x] = get_root(root[x]);
}

void merge(int x, int y) {  // 并查集 并
    int x_root = get_root(x);
    int y_root = get_root(y);
    if (x_root != y_root) {
        root[x_root] = y_root;
    }
}

int main() {
    int n;
    int m;
    int k;
    int pos = 0;
    scanf("%d %d %d", &n, &m, &k);
    init(m);
    for (int i = 1; i <= n; i++) {
        int a;
        int s;
        int c;
        int x;
        scanf("%d %d %d %d", &a, &s, &c, &x);
        q.emplace(1, c, x, a + s);
        // 当前还剩多少件  总库存 每天过期多少 单价
        // 当前这一批 可售卖数量
        // 就1件 初始库存 每天过期x
        // 首日的第一次的价格 a+s
        if (c > 1) {
            q.emplace(c - 1, c - 1, x, a);
        }
        // 有2件 就代表可以卖第2次  库存c-1
    }

    while (!q.empty()) {
        int day;
        Node cur = q.top();  // 当前批次物品
        q.pop();

        if (cur.delta == 0) {  // 当前批次的 每天过期0个 衰减
            day = N;           // 则day=N day最晚可销售日期
            // N=1e5 这是最晚销售日期
        } else {
            day = min(static_cast< int >(ceil(cur.full * 1.0 / cur.delta)), N);
        }
        // 9个 每天坏3个 最晚日期=第3天
        // 8个 每天坏3个 最晚日期=第3天

        day = get_root(day);  // 并查集find(最晚销售日期)
        // 一开始每一天都是自己本身 fa[1]=1 fa[2]=2
        if (day == 0) {
            // 如果最晚销售日期为 0 跳过下面
            continue;
        }
        // 在某一个最晚日期 卖了一个蔬菜后 当天蔬菜销售
        if (--cnt[day] == 0) {
            merge(day, day - 1);
        }

        // 当前批次的蔬菜件数大于 1 代表明天还能卖
        if (cur.cnt > 1) {
            // 当前可卖数量，初始库存都-1，其他不变
            q.emplace(cur.cnt - 1, cur.full - 1, cur.delta, cur.val);
        }

        pos++;
        // 前缀和构造： 卖的价格总和
        // 在每一件上实际可以理解成，能卖 p 天，每天 m 件，最多卖 pm 件
        // 按照最优策略，卖了 pos 件
        ans[pos] = ans[pos - 1] + cur.val;
    }

    for (int i = 1; i <= k; i++) {
        int p;
        scanf("%d", &p);  // 实际件数 pos
        cout << ans[min(p * m, pos)] << '\n';
        // 也许实际卖不了全部 pm 件
        // 但 Epos 件也许又超过了实际允许的天数
        // 因为上面预处理的数据 并没有考虑到底实际卖几天
    }

    return 0;
}
