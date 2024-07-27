#include <bits/stdc++.h>
#define F 10

using namespace std;

auto main() -> int
{
    char nol = 0;
    int num = 0;
    int xnum = 0;
    int onum = 0;
    int add = 1;
    int left = 1;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num = num * F + str[i] - '0';
        } else if (str[i] == '-')
        {
            onum += num * left * add;
            num = 0;
            add = -1;
        } else if (str[i] == '+')
        {
            onum += num * left * add;
            num = 0;
            add = 1;
        } else if (str[i] == '=')
        {
            onum += num * left * add;
            num = 0;
            left = -1;
            add = 1;
        } else if (str[i] >= 'a' && str[i] <= 'z')
        {
            nol = str[i];
            if (str[i - 1] < '0' || str[i - 1] > '9')
            {
                num = 1;
            }
            xnum += num * left * add;
            num = 0;
        }
    }
    onum += num * left * add;
    onum = -1 * onum;
    double ans = 1.0 * onum / xnum;
    if (ans == -0.0)
    {
        ans = 0;
    }
    printf("%c=%.3lf\n", nol, ans);
    return 0;
}
