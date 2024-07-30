/*

4
1 3
3 6
2 8
3 6
:11

4
1 5
6 3
7 8
3 5
:8
7

5
1 4
2 6
1 4
5 3
6 5
:10

*/

#include <iostream>
#include <stack>
#define N 1000001

int height[N + 1];
int strong[N + 1];
int finish[N + 1];
int left[N + 1];
int right[N + 1];

int main()
{
    int num;
    int maxn = 0;
    std::stack< int > sta;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> height[i] >> strong[i];
    }
    for (int i = 1; i <= num; i++)
    {
        if (sta.empty() || height[sta.top()] >= height[i])
        {
            sta.push(i);
        } else
        {
            while (!sta.empty() && height[sta.top()] < height[i])
            {
                int tmp = sta.top();
                sta.pop();
                right[tmp] = i;
            }
            sta.push(i);
        }
    }
    while (!sta.empty())
    {
        sta.pop();
    }
    for (int i = num; i > 0; i--)
    {
        if (sta.empty() || height[sta.top()] >= height[i])
        {
            sta.push(i);
        } else
        {
            while (!sta.empty() && height[sta.top()] < height[i])
            {
                int tmp = sta.top();
                sta.pop();
                left[tmp] = i;
            }
            sta.push(i);
        }
    }
    while (!sta.empty())
    {
        sta.pop();
    }
    for (int i = 1; i <= num; i++)
    {
        finish[left[i]] += strong[i];
        finish[right[i]] += strong[i];
    }
    for (int i = 1; i <= num; i++)
    {
        maxn = std::max(maxn, finish[i]);
    }
    std::cout << maxn;
    return 0;
}
