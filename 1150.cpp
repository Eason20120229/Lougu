#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    int ans = 0,t = 0;
    cin >> n >> k;
    while(n){
        ans += n;
        int h = n + t;
        n = h / k;
        t = h % k;
    }
    cout << ans;
    return 0;
}