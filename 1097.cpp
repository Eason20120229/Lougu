#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
int a[10000];
int cnt = 0;

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int t;
        cin >> t;
        if(!m[t]){
            m[t] = 1;
            a[cnt++] = t;
        }else{
            m[t]++;
        }
    }
    sort(a,a + cnt);
    for(int i = 0;i < cnt;i++){
        cout << a[i] << " " << m[a[i]] << endl;
    }
    return 0;
}