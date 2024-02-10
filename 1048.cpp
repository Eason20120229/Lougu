#include<bits/stdc++.h>
using namespace std;

int t[101],c[101];
int dp[1001];

int main(){
    int T,m;
    cin >> T >> m;
    for(int i = 1;i <= m;i++){
        cin >> t[i] >> c[i];
    }
    for(int i = 1;i <= m;i++){
        for(int j = T;j > 0;j--){
            if(j >= t[i]){
                dp[j] = max(dp[j],
                    dp[j - t[i]] + c[i]);
            }else{
                dp[j] = dp[j];
            }
        }
    }
    cout << dp[T];
    return 0;
}