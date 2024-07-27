#include <iostream>

using namespace std;

void print(int n){
    int a[20],i = 0,cnt = 0;
    while(n){
        if(n & 1) a[cnt++] = i;
        i++;
        n >>= 1;
    }
    for(int i = cnt - 1;i >= 1;i--){
        if(a[i] == 1) cout << "2+";
        else if(a[i] == 0) cout << "2(0)+";
        else{
            cout << "2(";
            print(a[i]);
            cout << ")+";
        }
    }
    if(a[0] == 1) cout << "2";
    else if(a[0] == 0) cout << "2(0)";
    else{
        cout << "2(";
        print(a[0]);
        cout << ")";
    }
}

int main(){
    int n;
    cin >> n;
    print(n);
    return 0;
}
