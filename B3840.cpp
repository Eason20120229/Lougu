#include <iostream>

using namespace std;

bool isPrime(int num) {
    bool res = true;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            res = false;
            break;
        }
    }
    return res;
}

int main() {
    int one;
    int two;
    int three = 0;
    cin >> one >> two;

    for (int i = one; i <= two; i++) {
        if (isPrime(i)) {
            three++;
        }
    }
    cout << three;
    return 0;
}
