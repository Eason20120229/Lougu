/*

复杂度：
    时间：O(n ^ 3)
    空间：O(n ^ 2)

错误1：
    应该求最大值，却求了最小值。
错误2：
    数组越界

*/

#include <bits/stdc++.h>
#define N 101

int num;
std::array< int, N > arr;  // 原数组
// dp[i][j] 代表 i~j 区间的最大价值
std::array< std::array< int, N >, N > use_dp;

int calc(int left, int right)  // 计算切除 left~right 的价值
{
    if (left == right)  // 如果相等，返回对应元素的值
    {
        return arr[left];
    }
    return abs(arr[left] - arr[right]) *
           (right - left + 1);  // 否则，返回题目要求
}

auto main() -> int
{
    // 输入
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i];
        use_dp[i][i] = arr[i];
    }
    // 开始dp
    for (int len = 0; len < num; len++)  // 遍历区间长度
    {
        for (int i = 1; len + i <= num; i++)  // 遍历左右端点
        {
            int right = len + i;
            use_dp[i][right] = calc(i, right);  // 初始化
            // 遍历切除部分
            for (int k = i + 1; k <= right; k++)
            {
                // 如题目要求
                use_dp[i][right] = std::max(use_dp[i][right],
                                            use_dp[i][k - 1] + calc(k, right));
            }
            for (int k = i; k < right; k++)
            {
                // 如题目要求
                use_dp[i][right] = std::max(use_dp[i][right],
                                            calc(i, k) + use_dp[k + 1][right]);
            }
        }
    }
    std::cout << use_dp[1][num];  // 输出结果
    return 0;
}
