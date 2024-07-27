#include <iostream>

using namespace std;

int deep,n;
bool flag;
int ans[10001];

void dfs(int cur){
    if(cur == deep){
        if(ans[cur] == n){
            flag = true;
        }
        return;
    }
    for(int i = 0;i <= cur;i++){
        if(ans[cur] + ans[i] <= n){
            int sum = ans[cur] + ans[i];
            for(int k = cur + 1;k < deep;k++) sum *= 2;
            if(sum < n) continue;
            ans[cur + 1] = ans[cur] + ans[i];
            dfs(cur + 1);
            if(flag) return;
        }
    }
}

int main(){
    cin >> n;
    while(n){
        ans[0] = 1;
        flag = false;
        int sum = 1;
        deep = 0;
        while(sum < n){
            sum <<= 2;
            deep++;
        }
        while(deep <= n){
            dfs(0);
            if(flag) break;
            deep++;
        }
        for(int i = 0;i < deep;i++){
            cout << ans[i] << " ";
        }
        cout << ans[deep] << endl;
        cin >> n;
    }
    return 0;
}
