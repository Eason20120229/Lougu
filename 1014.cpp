#include <iostream>

using namespace std;

int main(){
    int n,t = 0,i = 1;
    cin >> n;
    while(i + t <= n){
        t += i;
        i++;
    }
    int j = n - t;
    if(j == 0) i--;
    if(i % 2 == 0){
        if(j == 0) cout << i << "/" << 1;
        else cout << j << "/" << (i - j + 1);
    }else{
        if(j == 0) cout << 1 << "/" << i;
        else cout << (i - j + 1) << "/" << j;
    }
    return 0;
}
