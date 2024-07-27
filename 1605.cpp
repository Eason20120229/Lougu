#include <iostream>

using namespace std;

int ans = 0;
int n,m,t;
int s[2],e[2];
int w[4][2] = {1,0,-1,0,0,1,0,-1};
bool v[11][11] = {};
int g[11][11] = {};

bool check(int x,int y){
	if(x > 0 && x <= n && y > 0 && y <= m) return 1;
	return 0;
}

void dfs(int x,int y){
	if(x == s[0] && y == s[1]){
		ans++;
		return;
	}
	for(int i = 0;i < 4;i++){
		int tx = x + w[i][0],ty = y + w[i][1];
		if(check(tx,ty) && !g[tx][ty] && !v[tx][ty]){
			v[tx][ty] = 1;
			dfs(tx,ty);
			v[tx][ty] = 0;
		}
	}
}

int main(){
	cin >> n >> m >> t;
	cin >> s[0] >> s[1] >> e[0] >> e[1];
	while(t--){
		int x,y;
		cin >> x >> y;
		g[x][y] = 1;
	}
	v[s[0]][s[1]] = 1;
	dfs(s[0],s[1]);
	cout << ans;
	return 0;
}


