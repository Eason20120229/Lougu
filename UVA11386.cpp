#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int a[5003];

int main() {
    while (cin >> n) {
        unordered_map< int, int > mp;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                mp[a[i] + a[j]]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += mp[a[i]];
        }
        cout << ans << '\n';
    }
    return 0;
}
