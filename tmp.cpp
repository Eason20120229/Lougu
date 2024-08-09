#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int getnum()
{
    char a = getchar();
    char b = getchar();
    return (a - '0') * 10 + b - '0';
}

int p[14], k[14], h[14], t[14];

int main()
{
    char chr;
    while ((chr = getchar()) != '\n')
    {
        int num = getnum();
        if (chr == 'P')
        {
            p[num]++;
            cout << 'i';
        }
        if (chr == 'K')
        {
            k[num]++;
            cout << 'i';
        }
        if (chr == 'H')
        {
            h[num]++;
            cout << 'i';
        }
        if (chr == 'T')
        {
            t[num]++;
            cout << 'i';
        }
        cout << chr;
    }
    int sp = 0, sk = 0, sh = 0, st = 0;
    for (int i = 1; i <= 13; i++)
    {
        if (p[i] > 1 || k[i] > 1 || h[i] > 1 || t[i] > 1)
        {
            cout << "ERROR";
            return 0;
        }
        sp += p[i];
        sk += k[i];
        sh += h[i];
        st += t[i];
    }
    cout << 13 - sp << " " << 13 - sk << " " << 13 - sh << " " << 13 - st;
    return 0;
}
