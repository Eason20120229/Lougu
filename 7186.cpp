#include <iostream>
#define N 1001

using namespace std;

int num;
int qcnt;
int posx[N];  // 所在行
int posy[N];  // 所在列
int disx[N];  // 目标行
int disy[N];  // 目标列

// 更新后续询问的所在行和列
void move(int ansx, int ansy, int cur)
{
    for (int j = cur + 1; j <= qcnt; j++)
    {
        // 先移动整行，判断同行
        if (posx[j] == posx[cur])
        {
            posy[j] += ansy;    // 所在列移动
            if (posy[j] > num)  // 如果超出，到另一头
            {
                posy[j] -= num;
            }
        }
        // 再移动整列，判断同列（整行移动在这之前结束，所以要与移动后的结果比较）
        if (posy[j] == disy[cur])
        {
            posx[j] += ansx;    // 所在行移动
            if (posx[j] > num)  // 如果超出，到另一头
            {
                posx[j] -= num;
            }
        }
    }
}

int main()
{
    cin >> num >> qcnt;
    for (int i = 1; i <= qcnt; i++)
    {
        int value;  // 要移动的值
        cin >> value >> disx[i] >> disy[i];
        // 计算所在行和列（通过简单数学计算）
        posy[i] = value % num;
        if (posy[i] == 0)
        {
            posy[i] = num;
        }
        posx[i] = (value - posy[i]) / num + 1;
        // cout << posx[i] << " " << posy[i] << endl;
    }
    for (int i = 1; i <= qcnt; i++)
    {
        int ansx;  // 整行移动次数
        int ansy;  // 整列移动次数
        // 因为题目中说只能向右或下移动，所以要特判
        if (disx[i] >= posx[i])  // 在前面，直接移动过去
        {
            ansx = disx[i] - posx[i];
        } else  // 在后面，绕一圈过去
        {
            ansx = disx[i] - posx[i] + num;
        }
        if (disy[i] >= posy[i])  // 在前面，直接移动过去
        {
            ansy = disy[i] - posy[i];
        } else  // 在后面，绕一圈过去
        {
            ansy = disy[i] - posy[i] + num;
        }
        move(ansx, ansy, i);          // 更新后续询问的所在行和列
        cout << ansx + ansy << endl;  // 行和列需移动的次数总和就是答案
    }
    return 0;
}
