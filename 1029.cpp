#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    return y != 0 ? gcd(y, x % y) : x;
}

int main()
{
    int ans = 0;
    int x;
    int y;
    cin >> x >> y;
    for (int i = x; i <= y; i += x)
    {
        int j = x * y / i;
        int ggg = gcd(i, j);
        // cout << i << " " << j << " " << ggg << endl;
        if (ggg == x && i * j / ggg == y)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
