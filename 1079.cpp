#include<bits/stdc++.h>
using namespace std;

int main(){
    string p;
    string m;
    string k;
    char c[1000] = {};
    cin >> p >> m;
    int n = m.size();
    for(int i = 0;i <= n / p.size() + 1;i++){
        k += p;
    }
    for(int i = 0;i < n;i++){
        int t1,t2;
        if(m[i] >= 'A' && m[i] <= 'Z') t1 = 'A';
        else t1 = 'a';
        if(k[i] >= 'A' && k[i] <= 'Z') t2 = k[i] - 'A';
        else t2 = k[i] - 'a';
        c[i] = (m[i] - t1 - t2 + 26) % 26 + t1;
    }
    cout << c;
    return 0;
}