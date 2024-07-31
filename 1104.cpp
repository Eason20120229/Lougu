#include <algorithm>
#include <iostream>
#include <string>
#define N 101

struct oi
{
    std::string name;
    int y;
    int m;
    int d;
    int id;
} arr[N];

bool cmp(const oi &one, const oi &two)
{
    if (one.y == two.y)
    {
        if (one.m == two.m)
        {
            if (one.d == two.d)
            {
                return one.id > two.id;
            }
            return one.d < two.d;
        }
        return one.m < two.m;
    }
    return one.y < two.y;
}

auto main() -> int
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i].name >> arr[i].y >> arr[i].m >> arr[i].d;
        arr[i].id = i;
    }
    std::sort(arr + 1, arr + 1 + num, cmp);
    for (int i = 1; i <= num; i++)
    {
        std::cout << arr[i].name << std::endl;
    }
    return 0;
}
