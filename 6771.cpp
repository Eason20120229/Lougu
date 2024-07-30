#include <iostream>
#define N 10001

using namespace std;

int num;
int hei[N];
int above[N];
int dparr[N][2];
int total;

int main()
{
    ios::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int tmp;
        int tint;
        int icnt;
        cin >> tmp >> tint >> icnt;
        while (icnt-- != 0)
        {
            hei[++total] = tmp;
            above[total] = tint;
        }
    }
    for (int i = 1; i <= total; i++)
    {
        int tmp;
        int tmp2;
        dparr[i][0] = std::max(dparr[i - 1][0], dparr[i - 1][1]);
        if (dparr[i - 1][0] + hei[i] <= above[i])
        {
            tmp = dparr[i - 1][0] + hei[i];
        } else
        {
            tmp = 0;
        }
        if (dparr[i - 1][1] + hei[i] <= above[i])
        {
            tmp2 = dparr[i - 1][1] + hei[i];
        } else
        {
            tmp2 = 0;
        }
        dparr[i][1] = std::max(tmp, tmp2);
        std::cout << dparr[i][0] << " " << dparr[i][1] << "\n";
    }
    std::cout << std::max(dparr[total][0], dparr[total][1]);
    return 0;
}
