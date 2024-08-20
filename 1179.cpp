#include <iostream>
#define BASE 10

using namespace std;

int main()
{
    int left;
    int right;
    int ans = 0;
    cin >> left >> right;
    for (int i = left; i <= right; i++)
    {
        int tmp = i;
        while (tmp != 0)
        {
            if (tmp % BASE == 2)
            {
                ans++;
            }
            tmp /= BASE;
        }
    }
    cout << ans;
    return 0;
}
