#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    int n;
    string s[20];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++)
        cout << s[i];
    return 0;
}
