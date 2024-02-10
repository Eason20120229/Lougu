#include<bits/stdc++.h>
using namespace std;

int a[3] = {1,5,11};

int main(){
    int n;//1 5 11
    vector<int> dp;
    dp.push_back(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        int m = 1000001;
        for(int j = 0;j < 3 && a[j] <= i;j++){
            m = min(m,dp[i - a[j]] + 1);
        }
        dp.push_back(m);
    }
    cout << dp[n];
    return 0;
}