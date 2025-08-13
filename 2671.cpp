#include<bits/stdc++.h>
using namespace std;

int dat[100001];

vector<int> a[100001][2];
long long s1[100001],s2[100001],s3[100001];
long long sum = 0;

int mod(long long x){
    return x % 10007;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> dat[i];
        dat[i] = mod(dat[i]);
    }
    for(int i = 1;i <= n;i++){
        int c;
        cin >> c;
        a[c][i % 2].push_back(i);
    }
    for(int k = 1;k <= m;k++){
        for(int i = 0;i < a[k][0].size();i++){
            if(i == 0){
                s1[i] = mod(a[k][0][i] * dat[a[k][0][i]]);
                continue;
            }
            s1[i] = mod(s1[i - 1] + mod(a[k][0][i] * dat[a[k][0][i]]));
        }
        for(int i = 0;i < a[k][0].size();i++){
            if(i == 0){
                s2[i] = dat[a[k][0][i]];
                continue;
            }
            s2[i] = mod(s2[i - 1] + dat[a[k][0][i]]);
        }
        for(int i = 0;i < a[k][0].size();i++){
            if(i == 0){
                s3[i] = a[k][0][i];
                continue;
            }
            s3[i] = mod(s3[i - 1] + a[k][0][i]);
        }
        for(int i = 0;i < a[k][0].size();i++){
            sum += mod(mod((a[k][0].size() - i - 1) * a[k][0][i]) * dat[a[k][0][i]]);
            sum = mod(sum);
            sum += mod(s1[a[k][0].size() - 1] - s1[i]);
            sum = mod(sum);
            sum += mod(a[k][0][i] * mod(s2[a[k][0].size() - 1] - s2[i]));
            sum = mod(sum);
            sum += mod(dat[a[k][0][i]] * mod(s3[a[k][0].size() - 1] - s3[i]));
            sum = mod(sum);
        }

        for(int i = 0;i < a[k][1].size();i++){
            if(i == 0){
                s1[i] = mod(a[k][1][i] * dat[a[k][1][i]]);
                continue;
            }
            s1[i] = mod(s1[i - 1] + mod(a[k][1][i] * dat[a[k][1][i]]));
        }
        for(int i = 0;i < a[k][1].size();i++){
            if(i == 0){
                s2[i] = dat[a[k][1][i]];
                continue;
            }
            s2[i] = mod(s2[i - 1] + dat[a[k][1][i]]);
        }
        for(int i = 0;i < a[k][1].size();i++){
            if(i == 0){
                s3[i] = a[k][1][i];
                continue;
            }
            s3[i] = mod(s3[i - 1] + a[k][1][i]);
        }
        for(int i = 0;i < a[k][1].size();i++){
            sum += mod(mod((a[k][1].size() - i - 1) * a[k][1][i]) * dat[a[k][1][i]]);
            sum = mod(sum);
            sum += mod(s1[a[k][1].size() - 1] - s1[i]);
            sum = mod(sum);
            sum += mod(a[k][1][i] * mod(s2[a[k][1].size() - 1] - s2[i]));
            sum = mod(sum);
            sum += mod(dat[a[k][1][i]] * mod(s3[a[k][1].size() - 1] - s3[i]));
            sum = mod(sum);
        }
    }
    cout << mod(sum + 10007);
    return 0;
}