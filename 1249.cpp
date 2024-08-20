#include <iostream>

using namespace std;

int arr[10001];

int main()
{
    int num;
    int len = 0;
    int ans[10001] = {1};
    cin >> num;
    int tmp = num;
    for (int i = 2; tmp >= i; i++)
    {
        arr[i - 1] = i;
        tmp -= i;
        len++;
    }
    for (int i = 1, j = len; i <= tmp; i++, j--)
    {
        if (j == 0)
        {
            j = len;
        }
        arr[j]++;
    }
    int len_a = 1;
    for (int i = 1; i <= len; i++)
    {
        int j;
        int car = 0;
        for (j = 0; j < len_a || car != 0; j++)
        {
            ans[j] = ans[j] * arr[i] + car;
            car = ans[j] / 10;
            ans[j] %= 10;
        }
        len_a = j;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = len_a - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    return 0;
}
