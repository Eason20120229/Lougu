#include <iostream>

using namespace std;

int n,m,f[2000005];
int a[500001];

inline void buildtree(int k,int l,int r){
	if(l == r){
		f[k] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	buildtree(k * 2,l,m);
	buildtree(k * 2 + 1,m + 1,r);
	f[k] = f[k * 2] + f[k * 2 + 1];
}

inline void add(int k,int l,int r,int x,int y){
	f[k] += y;
	if(l == r){
		return;
	}
	int m = (l + r) >> 1;
	if(x <= m){
		add(k * 2,l,m,x,y);
	}else{
		add(k * 2 + 1,m + 1,r,x,y);
	}
}

inline int calc(int k,int l,int r,int s,int t){
	if(s == l && r == t) return f[k];
	int m = (l + r) >> 1;
	if(t <= m) return calc(k * 2,l,m,s,t);
	else if(s > m) return calc(k * 2 + 1,m + 1,r,s,t);
	else return calc(k * 2,l,m,s,m) + calc(k * 2 + 1,m + 1,r,m + 1,t);
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	buildtree(1,1,n);
	while(m--){
		int t,x,y;
		cin >> t >> x >> y;
		if(t == 1) add(1,1,n,x,y);
		else cout << calc(1,1,n,x,y) << endl;
	}
	return 0;
}