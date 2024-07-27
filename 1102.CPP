#include <algorithm>
#include <iostream>
#define N 200001

int arr[N];

int main()
{
    int num;
    int check;
    long long ans = 0;
    std::cin >> num >> check;
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &arr[i]);
    }
    std::sort(arr + 1, arr + num + 1);
    int one = 1;
    int two = 2;
    int point = two;
    while (two <= num)
    {
        // std::cout << two << " " << point << "\n";
        // std::cout << one << " " << two << " " << ans << "\n";
        while (point <= num && arr[point] == arr[point + 1])
        {
            point++;
        }
        if (arr[two] - arr[one] == check)
        {
            ans += point - two + 1;
            one++;
        } else if (arr[two] - arr[one] > check)
        {
            one++;
        } else
        {
            two = point + 1;
            point = two;
        }
        if (one >= two)
        {
            two = point + 1;
            point = two;
        }
    }
    std::cout << ans;
    return 0;
}
