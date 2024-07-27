#include <iostream>

using namespace std;

int a[1000001];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    while(m--){
        int t;
        scanf("%d",&t);
        int l = 1,r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(a[mid] >= t){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if(a[r] != t) cout << -1 << " ";
        else cout << r << " ";
    }
    return 0;
}
