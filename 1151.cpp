#include <iostream>
#define MIN 10000
#define MAX 30000

using namespace std;

int main()
{
    int k;
    bool f = 1;
    cin >> k;
    for (int i = MIN; i <= MAX; i++)
    {
        int j = i / 100;
        int g = i / 10 % 1000;
        int h = i % 1000;
        if (j % k == 0 && g % k == 0 && h % k == 0)
        {
            f = 0;
            cout << i << endl;
        }
    }
    if (f)
    {
        cout << "No";
    }
    return 0;
}
