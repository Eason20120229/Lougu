#include <iostream>

using namespace std;

int dp[30000] = {};

int main()
{
    int v[26] = {};
    int w[26] = {};
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j > 0; j--)
        {
            if (j >= v[i])
            {
                dp[j] = max(dp[j - v[i]] + v[i] * w[i], dp[j]);
            }
        }
    }
    cout << dp[n];
    return 0;
}
