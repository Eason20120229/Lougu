#include <iostream>
#define MON 12
#define SE  100
#define LU  1.2

using namespace std;

int main()
{
    int s[MON];
    int last = 0;
    int mot = 0;
    for (int i = 0; i < MON; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < MON; i++)
    {
        int j = last + 300 - s[i];
        if (j < 0)
        {
            cout << "-" << i + 1;
            return 0;
        }
        mot += j - j % SE;
        last = j % SE;
    }
    cout << (mot * LU + last);
    return 0;
}
