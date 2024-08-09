#include <iostream>

using namespace std;

int n;
int arr[100001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            flag = false;
        }
    }
    if (!flag)
    {
        cout << n - 1;
    } else
    {
        cout << 0;
    }
    return 0;
}
