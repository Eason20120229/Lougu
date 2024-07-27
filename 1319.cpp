#include <iostream>

using namespace std;

int a[40001];

int main(){
    int n,num = 0,l = 0;
    cin >> n;
    while(cin >> a[++num]);
    for(int i = 1;i <= num;i++){
        int k = (i - 1) % 2;
        for(int j = 0;j < a[i];j++){
            cout << k << " ";
            l++;
            if(l % n == 0) cout << endl;
        }
    }
    return 0;
}
