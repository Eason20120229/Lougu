#include<bits/stdc++.h>
using namespace std;

long long dp[21][21] = {};
long long c[21][21];

int main(){
    memset(dp,0,sizeof(dp));
    memset(c,0,sizeof(dp));
    int n,m;
    int l,r;
    cin >> n >> m >> l >> r;
    c[l][r] = 1;
    c[l + 2][r + 1] = 1;
    c[l + 1][r + 2] = 1;
    c[l - 1][r + 2] = 1;
    c[l - 2][r + 1] = 1;
    c[l - 2][r - 1] = 1;
    c[l - 1][r - 2] = 1;
    c[l + 1][r - 2] = 1;
    c[l + 2][r - 1] = 1;
    if(c[0][0] == 1){
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            if(!c[i][j]){
                if(i) dp[i][j] += dp[i - 1][j];
                if(j) dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}