#include <iostream>

using namespace std;

int pri[10001];
bool l[10001];

void print(int k,int cnt){
    for(int i = 1;i <= cnt;i++){
        if(pri[i] > k) break;
        if(!l[k - pri[i]]){
            cout << k << "=" << pri[i] <<
                "+" << k - pri[i] << endl;
            break;
        }
    }
}

int getPri(int n){
    int cnt = 0;
    l[0] = l[1] = 1;
    for(int i = 2;i <= n;i++){
        if(!l[i]) pri[++cnt] = i;
        for(int j = 1;j <= cnt;j++){
            if(i * pri[j] > n) break;
            l[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    return cnt;
}

int main(){
    int n,cnt;
    cin >> n;
    cnt = getPri(n);
    for(int i = 4;i <= n;i += 2){
        print(i,cnt);
    }
    return 0;
}
