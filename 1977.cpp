/*

6 3 10 5
1 2
2 3
3 4
:34

6 2 10 5
1 2
2 3
:impossible

*/

#include <algorithm>
#include <iostream>
#define N   101
#define INF 0x3f3f3f3f

using namespace std;

int num;
int cnt;
int basic;
int price[N];
int tim[N];
int dparr[N][N];

int main()
{
    int tmp;
    int sum = 0;
    cin >> num >> cnt >> basic >> tmp;
    for (int i = 1; i <= cnt; i++)
    {
        cin >> tim[i] >> price[i];
        sum += price[i];
    }
    if (sum < num)
    {
        cout << "impossible";
        return 0;
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (i == 1)
            {
                dparr[i][j] = j <= price[i] ? tim[i] * j + basic : INF;
            } else
            {
                dparr[i][j] = dparr[i - 1][j];
                for (int k = 1; k <= min(j, price[i]); k++)
                {
                    dparr[i][j] = min(dparr[i][j],
                                      dparr[i - 1][j - k] + tim[i] * k + basic);
                }
            }
            // cout << dparr[i][j] << " ";
        }
        // cout << endl;
    }
    cout << dparr[cnt][num];
    return 0;
}
