#include <iostream>
#define M 101
#define N 1001

using std::cin, std::cout;

int arr[M];
int times[N];

int main()
{
    int num;
    int cnt;
    int ans = 0;
    int maxx = 0;
    int idt = 1;
    cin >> num >> cnt;
    for (int i = 1; i <= num; i++)
    {
        cin >> times[i];
        if (i <= cnt)
        {
            arr[i] = times[i];
            idt = i;
        }
    }
    while (idt < num)
    {
        for (int i = 1; i <= cnt; i++)
        {
            if (arr[i] > 0)
            {
                arr[i]--;
                if (arr[i] == 0 && idt < num)
                {
                    idt++;
                    arr[i] = times[idt];
                }
            }
        }
        ans++;
    }
    for (int i = 1; i <= cnt; i++)
    {
        maxx = std::max(maxx, arr[i]);
    }
    ans += maxx;
    cout << ans;
    return 0;
}
