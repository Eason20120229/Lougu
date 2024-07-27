#include<bits/stdc++.h>
using namespace std;

struct node{
    int num = 0,l = 0;
    int near[1001];
}a[1001];

int n,m;
int u,v;
int book[1001];

int dfs(int i){
    // cout << endl;
    // for(int j = 1;j <= n;j++){
    //     cout << book[j] << " ";
    // }
    // cout << endl;
    if(i == v){
        return 1;
    }
    for(int j = 1;j <= a[i].num;j++){
        if(!book[a[i].near[j]] && a[a[i].near[j]].l == 0){
            book[a[i].near[j]] = 1;
            int t = dfs(a[i].near[j]);
            book[a[i].near[j]] = 0;
            if(t) return 1;
        }
    }
    return 0;
}

int main(){
    int cnt = 0;
    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        a[u].near[++a[u].num] = v;
        a[v].near[++a[v].num] = u;
    }
    cin >> u >> v;
    book[u] = 1;
    if(!dfs(u)){
        cout << -1;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        if(i != u && i != v){
            a[i].l = 1;
            if(!dfs(u)) cnt++;
            a[i].l = 0;
        }
    }
    cout << cnt;
    return 0;
}