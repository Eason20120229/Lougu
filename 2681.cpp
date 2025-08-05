#include <bits/stdc++.h>
#define N 1001

using namespace std;

int tmp[N];
int arr[N];

int main()
{
    int num;
    int qcnt;
    cin >> num >> qcnt;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= qcnt; i++)
    {
        int opt;
        int one;
        int two;
        cin >> opt >> one >> two;
        if (opt == 0)
        {
            for (int i = one; i <= two; i++)
            {
                tmp[i] = arr[i];
            }
            sort(tmp + one, tmp + two + 1);
            int ans = tmp[one];
            int ansm = 1;
            int tmc = 1;
            for (int j = one + 1; j <= two; j++)
            {
                if (tmp[j - 1] == tmp[j])
                {
                    tmc++;
                } else
                {
                    if (ansm < tmc)
                    {
                        ansm = tmc;
                        ans = tmp[j - 1];
                    }
                    tmc = 1;
                }
            }
            if (ansm < tmc)
            {
                ansm = tmc;
                ans = tmp[two];
            }
            cout << ans << endl;
        } else
        {
            arr[one] = two;
        }
    }
    return 0;
}
