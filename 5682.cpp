#include <algorithm>
#include <cstdio>

int arr[200001], ans[2];

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &arr[i]);
    }
    num = static_cast< int >(std::unique(arr + 1, arr + num + 1) - arr) - 1;
    std::sort(arr + 1, arr + num + 1);
    if (num < 2)
    {
        printf("-1");
    } else
    {
        printf("%d", ans[1]);
    }
    return 0;
}
