#include <cmath>
#include <iostream>

using namespace std;

bool arr[1000001][2];

int main()
{
    int idt = 0;
    int col = 0;
    int val = 1000005;
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i][0];
    }
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i][1];
    }
    int ccol;
    int ccur;
    cin >> ccol >> ccur;
    for (int i = 1; i <= num; i++)
    {
        if (!arr[i][0])
        {
            if (abs(ccur - i) < val || (abs(ccur - i) == val && ccol == 0))
            {
                idt = i;
                col = 0;
                val = abs(ccur - i);
            }
        }
    }
    for (int i = 1; i <= num; i++)
    {
        if (!arr[i][1])
        {
            if (abs(ccur - i) < val || (abs(ccur - i) == val && ccol == 1))
            {
                idt = i;
                col = 1;
                val = abs(ccur - i);
            }
        }
    }
    if (idt == 0)
    {
        cout << -1;
    } else
    {
        cout << col << " " << val;
    }
    return 0;
}
