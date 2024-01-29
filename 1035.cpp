#include<bits/stdc++.h>
using namespace std;

int main(){
    double Sn = 0;
    int k,i;
    cin >> k;
    for(i = 1;Sn - k <= 0;i++){
        Sn += 1.0 / i;
    }
    cout << i - 1;
    return 0;
}