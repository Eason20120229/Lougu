#include <iostream>
using namespace std;

bool isPrime(int num) {
    bool res = true;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            res == false;
            break;
        }
    }
    return res;
}

int main() {
    int A, B, C = 0;
    cin >> A >> B;

    for (int i = A; i <= B; i++) {
        if (isPrime(i)) {
            C++;
        }
    }

    cout << C;

    return 0;
}
