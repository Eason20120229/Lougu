/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-12-02 17:14
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

priority_queue< int, vector< int >, greater< int > > q;

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        q.push(t);
    }
    while (true)
    {
        int t = 0;
        t += q.top();
        q.pop();
        if (q.empty())
            break;
        t += q.top();
        q.pop();
        ans += t;
        q.push(t);
    }
    cout << ans;
    return 0;
}
