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
    }
    while(m--){
        int x,a,b;
        cin >> x >> a >> b;
        if(x == 1) update(a,b);
        if(x == 2) cout << (sum(b) - sum(a - 1)) << endl;
    }
    return 0;
}