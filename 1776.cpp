#include <iostream>
#define N 100001
#define M 40001

using namespace std;

int cnt;
int arrw[N];
int arrm[N];
int dparr[N];

auto main() -> int
{
    int num;
    int weight;
    cin >> num >> weight;
    for (int i = 1; i <= num; i++)
    {
        int tmpm;
        int tmpw;
        int tmpc;
        cin >> tmpm >> tmpw >> tmpc;
        for (int j = 1; j <= tmpc; j <<= 1)
        {
            arrw[++cnt] = tmpw * j;
            arrm[cnt] = tmpm * j;
            tmpc -= j;
        }
        if (tmpc > 0)
        {
            arrw[++cnt] = tmpw * tmpc;
            arrm[cnt] = tmpm * tmpc;
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = weight; j >= arrw[i]; j--)
        {
            dparr[j] = max(dparr[j], dparr[j - arrw[i]] + arrm[i]);
        }
    }
    cout << dparr[weight];
    return 0;
}
