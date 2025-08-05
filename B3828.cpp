#include <cmath>
#include <iostream>
#define M 998244353

using namespace std;

bool isp(long long num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }
    for (long long i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int left;
    int right;
    long long ans = 1;
    bool flag = false;
    cin >> left >> right;
    for (long long i = ceil(sqrt(left)); i * i <= right; i++)
    {
        if (i * i >= left)
        {
            long long sum = 0;
            long long tmp = i * i;
            while (tmp != 0)
            {
                sum += tmp % 10;
                tmp /= 10;
            }
            if (isp(sum))
            {
                long long tm1 = (i % M * (i % M)) % M;
                ans *= tm1;
                ans %= M;
                flag = true;
            }
            // cout << ans << " ";
        }
    }
    if (!flag)
    {
        cout << 0;
    } else
    {
        cout << ans;
    }
    return 0;
}
