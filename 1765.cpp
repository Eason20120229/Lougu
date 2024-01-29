#include<bits/stdc++.h>
using namespace std;

int a[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,
    2,3,1,2,3,4,1,2,3,1,2,3,4};

int main(){
    string s;
    getline(cin,s);
    int ans = 0;
    int i = 0;
    while(i < s.length()){
        if(s[i] == ' ') ans++;
        else if(s[i] >= 'a' && s[i] <= 'z'){
            ans += a[s[i] - 'a'];
        }
        i++;
    }
    cout << ans;
    return 0;
}