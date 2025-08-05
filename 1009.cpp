#include <iostream>
#include <vector>

using namespace std;

int myCompare(string a, string b) {
    if (a.size() != b.size()) {
        if (a.size() > b.size())
            return 1;
        else
            return -1;
    } else {
        if (a > b)
            return 1;
        else if (a == b)
            return 0;
        else
            return -1;
    }
}

string myAdd(string a, string b) {
    int n = max(a.size(), b.size()) + 1;
    vector< int > ans(n, 0);

    int i = a.size() - 1;
    int j = b.size() - 1;
    int k = n - 1;
    while (i >= 0 && j >= 0) {
        ans[k--] = (a[i--] - '0') + (b[j--] - '0');
    }
    while (j >= 0) {
        ans[k--] = (b[j--] - '0');
    }
    while (i >= 0) {
        ans[k--] = (a[i--] - '0');
    }
    string c;
    for (int i = n - 1; i > 0; i--) {
        if (ans[i] >= 10) {
            ans[i] -= 10;
            ans[i - 1]++;
        }
        c.insert(0, 1, ans[i] + '0');
    }

    if (ans[0] > 0) {
        c.insert(0, 1, ans[0] + '0');
    }
    return c;
}

string myMultiply(string a, string b) {
    if (a == "0" || b == "0")
        return "0";
    vector< int > ans;
    int n = a.size();
    int m = b.size();
    ans.resize(n + m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = n + m - 1; i > 0; i--) {
        if (ans[i] >= 10) {
            ans[i - 1] += (ans[i] / 10);
            ans[i] %= 10;
        }
    }
    string c;
    bool flag = true;
    for (int t = 0; t < n + m; t++) {
        if (flag && ans[t] == 0)
            continue;
        flag = false;
        c.push_back(ans[t] + '0');
    }
    return c;
}

int main() {
    int num;
    std::cin >> num;
    string ans = "0";
    string tmp = "1";
    for (int i = 1; i <= num; i++) {
        tmp = myMultiply(tmp, to_string(i));
        ans = myAdd(ans, tmp);
    }
    std::cout << ans;
    return 0;
}
