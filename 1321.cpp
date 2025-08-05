#include <iostream>
#include <string>

using namespace std;

int ans1 = 0;
int ans2 = 0;
string str;

int main() {
    cin >> str;
    str += '.';
    for (int i = 0; i < str.size() - 1; i++) {
        switch (str[i]) {
        case 'b':
            if (str[i + 1] != 'o') {
                ans1++;
            }
            break;
        case 'o':
            if (str[i + 1] != 'y') {
                ans1++;
            }
            break;
        case 'y': ans1++; break;
        case 'g':
            if (str[i + 1] != 'i') {
                ans2++;
            }
            break;
        case 'i':
            if (str[i + 1] != 'r') {
                ans2++;
            }
            break;
        case 'r':
            if (str[i + 1] != 'l') {
                ans2++;
            }
            break;
        case 'l': ans2++; break;
        }
    }
    cout << ans1 << endl << ans2;
    return 0;
}
