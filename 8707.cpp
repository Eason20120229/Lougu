#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[101];
int dp[101][10001];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 0;i <= n;i++) dp[i][0] = 1;
    dp[1][a[1]] = 1;
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(j >= a[i])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
            else dp[i][j] = dp[i - 1][j];
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[n][m];
    return 0;
}