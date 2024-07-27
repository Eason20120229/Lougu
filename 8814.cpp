/*

没想到用二分...
复杂度
    时间：O(k logm)
    空间：O(1)

*/

#include <cmath>
#include <cstdint>
#include <iostream>
#define M 1000000001

using std::cin, std::cout, std::endl;

int main()
{
    // e * d = p * q - p - q + 2, n = p * q, m = n - e * d + 2 = p + q
    int num;
    cin >> num;
    while (num-- != 0)
    {
        int64_t nint;
        int64_t dint;
        int64_t eint;
        int64_t mint;
        cin >> nint >> dint >> eint;
        mint = nint - eint * dint + 2;
        int64_t left = 1;
        int64_t right = mint / 2;
        while (left < right)
        {
            int64_t mid = (left + right) >> 1;
            int64_t jint = mint - mid;
            if (jint * mid < nint)
            {
                left = mid + 1;
            } else
            {
                right = mid;
            }
            // cout << left << " " << mid << " " << right << endl;
        }
        if (left * (mint - left) != nint)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << left << " " << mint - left << endl;
    }
    return 0;
}
