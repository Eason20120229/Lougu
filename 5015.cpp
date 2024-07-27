#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int ans = s.length();
    int i = ans;
    while(--i >= 0){
        if(s[i] == ' ') ans--;
    }
    cout << ans;
    return 0;
}
