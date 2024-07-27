#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,h = 0,j;
    int a[100] = {};
    cin >> N;
    while(cin >> j){
        a[h++] = j;
    }
    sort(a,a + h);
    int m,n;
    for(int i = 0;i < h - 1;i++){
        if(a[i] + 2 == a[i + 1]){
            m = a[i] + 1;
        }
        if(a[i] == a[i + 1]){
            n = a[i];
        }
    }
    cout << m << " " << n;
    return 0;
}