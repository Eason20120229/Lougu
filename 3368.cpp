#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;

int n,m;
int tree[500001];

void update(int i,int d){
    while(i <= n){
        tree[i] += d;
        i += lowbit(i);
    }
}

int sum(int i){
    int x = 0;
    while(i){
        x += tree[i];
        i -= lowbit(i);
    }
    return x;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int a;
        cin >> a;
        update(i,a);
        update(i + 1,-a);
    }
    while(m--){
        int x;
        cin >> x;
        if(x == 1){
            int l,r,d;
            cin >> l >> r >> d;
            update(l,d);
            update(r + 1,-d);
        }else if(x == 2){
            int t;
            cin >> t;
            cout << sum(t) << endl;
        }
    }
    return 0;
}