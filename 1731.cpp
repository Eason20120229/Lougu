/*
记忆化
最优性
可行性(优化定义域)
*/



#include <iostream>

using namespace std;

int n,m,s = 0x7fffffff,minn[21],mins[21];

void dfs(int now,int r,int h,int tn,int ts){
	if(now == 0){
		if(tn == n){
			s = min(s,ts);
		}
		return;
	}
	//如果当前面积已经大于最优解，放弃
	if(ts + mins[now - 1] >= s) return;
	if(tn + minn[now - 1] > n) return;
	if(2 * (n - tn) / r + ts >= s) return;
	for(int i = r - 1;i >= now;i--){ //更改下界
		int maxh = min(h - 1,(n - minn[now - 1] - tn) / i / i);
		for(int j = maxh;j >= now;j--){
			if(now == m) ts = i * i;
			dfs(now - 1,i,j,tn + i * i * j,ts + 2 * i * j);
		}
	}
}

int main(){

	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		mins[i] = mins[i - 1] + 2 * i * i;
		minn[i] = minn[i - 1] + i * i * i;
	}
	dfs(m,n,n,0,0);
	if(s == 0x7fffffff){
		cout << 0;
		return 0;
	}
	cout << s;
	return 0;
}
