/*

time:1.7h
Time: O(n)
Space: O(n)

思路：
利用普拉特语法分析器的原理，并将建树过程简化为求值，顺便统计短路的数量。


*/

#include <iostream>
#include <string>

using namespace std;

struct
{
    string str;
    int cur;  // 当前位置
} input;      // 存储字符串

int ans0;      // | 短路的数量
int ans1;      // & 短路的数量
int map[301];  // 存符号的优先级

int round(int score);

int eval(int p, int score)  // p 为当前运算的优先级，score 决定是否计分
{
    int left;  // left 为进行的下一个运算的左操作数
    if (input.str[input.cur] == '(')  // 如果是 '(' 就读取整个括号内的式子
    {
        left = round(score);
    } else if (input.str[input.cur] <= '1' && input.str[input.cur] >= '0')
    {
        left = input.str[input.cur] - '0';  // 计算实际数值
        input.cur++;                        // 跳过数字
    }
    for (; input.cur < input.str.size(); input.cur++)
    {
        // 如果运算符优先级更高，说明右操作数为此运算的结果，因为这个运算会先执行
        if (map[input.str[input.cur]] > p)
        {
            if (input.str[input.cur] == '|')
            {
                if (left == 1)  // 形成短路
                {
                    ans0 += score;
                    input.cur++;  // 跳过当前符号
                    eval(map[input.str[input.cur - 1]], 0);  // 跳过右操作数
                    left = 1;
                } else
                {
                    input.cur++;  // 跳过当前符号
                    // 计算
                    left = left | eval(map[input.str[input.cur - 1]], score);
                }
            } else if (input.str[input.cur] == '&')
            {
                if (left == 0)  // 形成短路
                {
                    ans1 += score;
                    input.cur++;  // 跳过当前符号
                    eval(map[input.str[input.cur - 1]], 0);  // 跳过右操作数
                    left = 0;
                } else
                {
                    input.cur++;  // 跳过当前符号
                    // 计算
                    left = left & eval(map[input.str[input.cur - 1]], score);
                }
            }
        } else
        {
            // 如果为优先级低的或' )' ，返回到上个数的位置，让上一级处理
            input.cur--;
            break;
        }
    }
    return left;
}

int round(int score)  // 读括号
{
    input.cur++;               // 跳过'('
    int tmp = eval(0, score);  // 处理括号内的表达式
    input.cur++;               // 到达 ')' 的位置
    input.cur++;               // 跳过')'
    return tmp;
}

int main()
{
    cin >> input.str;
    input.cur = 0;  // 从第一个字符开始遍历
    // 处理各符号的优先级
    map[')'] = -1;
    map['&'] = 2;
    map['|'] = 1;
    cout << eval(0, 1) << endl;  // 用最低优先级，处理整个字符串
    cout << ans1 << " " << ans0;
    return 0;
}
