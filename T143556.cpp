#include <iostream>

using namespace std;

int arr[102][102];

int main()
{
    int num;
    int sum = 0;
    int ans = 0;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        arr[0][i] = 255;
        arr[num + 1][i] = 255;
    }
    for (int i = 1; i <= num; i++)
    {
        arr[i][0] = 255;
        arr[i][num + 1] = 255;
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] <= 50)
            {
                sum++;
            }
        }
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (arr[i][j] <= 50 && (arr[i - 1][j] > 50 || arr[i + 1][j] > 50 ||
                                    arr[i][j - 1] > 50 || arr[i][j + 1] > 50))
            {
                ans++;
            }
        }
    }
    cout << sum << " " << ans;
    return 0;
}
