#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int j;
    for(int i = 2;i <= sqrt(n);i++){
        if(n % i == 0){
            j = i;
            break;
        }
    }
    cout << n / j;
    return 0;
}