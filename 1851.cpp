#include <cstdint>
#include <iostream>

using namespace std;

auto get(int64_t num) -> int64_t
{
    int64_t ans = 0;
    for (int64_t i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            ans += i;
        }
    }
    return ans;
}

auto main() -> int
{
    int down;
    cin >> down;
    for (int64_t i = down;; i++)
    {
        int64_t tmp = get(i);
        if (get(tmp) == i && tmp != i)
        {
            cout << i << " " << tmp << endl;
            break;
        }
        // cout << tmp << " " << get(tmp) << " " << i << endl;
    }
    return 0;
}
