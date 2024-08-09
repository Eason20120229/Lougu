/*



*/

#include <iostream>

using namespace std;

void out(bool flag)
{
    if (flag)
    {
        cout << "Yes";
    } else
    {
        cout << "No";
    }
    cout << endl;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        int one;
        int two;
        cin >> one >> two;
        if (two % 2 == 0)
        {
            out(one == 0);
        } else
        {
            out(one != 0);
        }
    }
    return 0;
}
