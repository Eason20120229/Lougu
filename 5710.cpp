#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0 && n > 4 && n <= 12) {
        cout << "1 ";
    } else {
        cout << "0 ";
    }
    if (n % 2 == 0 || (n > 4 && n <= 12)) {
        cout << "1 ";
    } else {
        cout << "0 ";
    }
    if (n % 2 == 0 || (n > 4 && n <= 12)) {
        if (n % 2 == 0 && n > 4 && n <= 12) {
            cout << "0 ";
        } else {
            cout << "1 ";
        }
    } else {
        cout << "0 ";
    }
    if (n % 2 != 0 && n <= 4 || n > 12) {
        cout << "1 ";
    } else {
        cout << "0 ";
    }
    return 0;
}
