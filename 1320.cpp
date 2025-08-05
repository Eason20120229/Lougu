#include <cmath>
#include <iostream>
#define N 10001

using namespace std;

int mcnt = 0;
int arr[N];

int main()
{
    int last = '0';
    int num = 0;
    int cnt = 0;
    int chr;
    while ((chr = getchar()) != EOF)
    {
        if (chr == '\n')
        {
            continue;
        }
        num++;
        if (last == chr)
        {
            cnt++;
        } else
        {
            arr[++mcnt] = cnt;
            cnt = 1;
        }
        last = chr;
    }
    if (cnt != 0)
    {
        arr[++mcnt] = cnt;
    }
    cout << static_cast< int >(sqrt(num));
    for (int i = 1; i <= mcnt; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
