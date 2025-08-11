#include <iostream>
#define M 998244353

using namespace std;

long long n;

int main() {
    cin >> n;
    n++;
    long long t = (n / M - 1);
    long long ans = n % M * ((t + 1) % M) % M;
    cout << ans;
    return 0;
}
