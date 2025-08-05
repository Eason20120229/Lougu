#include <iostream>
#define INF 2000000000

using namespace std;

int main()
{
    int num;
    cin >> num;
    if (num == 1)
    {
        cout << INF << " " << INF;
    } else if (num == 2)
    {
        for (int i = 1; i <= 1000000; i++)
        {
            cout << "a";
        }
    } else
    {
        cout << 100 << endl;
        for (int i = 1; i <= 100; i++)
        {
            cout << "1 ";
        }
    }
    return 0;
}
