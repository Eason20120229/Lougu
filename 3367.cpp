#include <iostream>
#define N 10001

int fath[N];  // fath[i] 表示第 i 个节点的父节点

auto find(int cur) -> int  // 查找所属集合
{
    return fath[cur] == cur ? cur : fath[cur] = find(fath[cur]);
}

void merge(int cur1, int cur2)  // 合并 cur1 和 cur2 所在的集合
{
    cur1 = find(cur1);
    cur2 = find(cur2);
    if (cur1 != cur2)  // 如果集合不同，合并
    {
        fath[cur1] = cur2;
    }
}

int main()
{
    int num;
    int cnt;
    std::cin >> num >> cnt;
    // 初始化
    for (int i = 1; i <= num; i++)
    {
        fath[i] = i;
    }
    // 输入
    while (cnt-- > 0)
    {
        int one;
        int two;
        int three;
        std::cin >> one >> two >> three;
        if (one == 1)
        {
            merge(two, three);  // 合并
        } else
        {
            if (find(two) == find(three))  // 查找对应集合，并判断是否相等
            {
                std::cout << "Y";
            } else
            {
                std::cout << "N";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
