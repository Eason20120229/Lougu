#include <iostream>
#define int long long

using namespace std;

signed main()
{
    int one;
    int two;
    int zheng = 0;
    int chang = 0;
    cin >> one >> two;
    for (int i = 1; i <= one; i++)
    {
        for (int j = 1; j <= two; j++)
        {
            int tmp = (one - i + 1) * (two - j + 1);
            if (i == j)
            {
                zheng += tmp;
            } else
            {
                chang += tmp;
            }
        }
    }
    cout << zheng << " " << chang;
    return 0;
}
