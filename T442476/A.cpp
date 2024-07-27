#include <iostream>
#include <cmath>

using namespace std;

int a[26],b[26];

int main(){
    string s,t;
    int ans = 0;
    cin >> s >> t;
    for(int i = 0;i < s.size();i++){
        a[s[i] - 'a']++;
    }
    for(int i = 0;i < t.size();i++){
        b[t[i] - 'a']++;
    }
    for(int i = 0;i < 26;i++){
        ans += min(a[i],b[i]);
    }
    cout << ans;
}
