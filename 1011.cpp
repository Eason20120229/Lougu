#include <iostream>

using namespace std;

struct g{
    int x,one;
};

int main(){
    int a,n,m,x;
    g f[21] = {};
    cin >> a >> n >> m >> x;
    if(x == n){
        cout << 0;
        return 0;
    }
    if(x == 1 || x == 2){
        cout << a;
        return 0;
    }
    f[1].one = a;
    f[2].x = 1;
    for(int i = 3;i < n;i++){
        f[i].x = f[i - 1].x + f[i - 2].x;
        f[i].one = f[i - 1].one + f[i - 2].one;
    }
    int x1 = (m - f[n - 1].one - a) / (f[n - 1].x - 1);    cout << (f[x].x * x1 + f[x].one + a - x1);
    return 0;
}
