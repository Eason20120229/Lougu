#include <iostream>
#define N 31

using namespace std;

int n,m;
long long dp[N][N][N];

int f(int x){
    return x % n == 0 ? n : x % n;
}

int main() {
    cin >> n >> m;
    if(n == 1){
        cout << 1;
        return 0;
    }
    if(n == 2){
        if(m % 2 == 0){
            cout << 1;
        }else{
            cout << 0;
        }
        return 0;
    }
    for(int j = 1;j <= n;j++){
        dp[0][j][j] = 1;
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                dp[i][j][k] = dp[i - 1][j][f(k - 1)] + dp[i - 1][j][f(k + 1)];
            }
        }
    }
    cout << dp[m][1][1];
    return 0;
}
