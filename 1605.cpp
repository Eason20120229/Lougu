#include <iostream>
using namespace std;

int n,m,h;
int ans = 0;
int s[2],e[2];
int w[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int g[10][10];
int f[10][10];

void dfs(int x,int y){
	if(x == e[0] && y == e[1]){
		ans++;
		return;
	}
	for(int i = 0;i < 4;i++){
		int sx = x + w[i][0];
		int sy = y + w[i][1];
		if(f[sx][sy] == 0 && g[sx][sy] == 1){
			f[sx][sy] = 1;
			dfs(sx,sy);
			f[sx][sy] = 0;
		}
	}
}

int main(){
	cin >> n >> m >> h;
	cin >> s[0] >> s[1]; 
	cin >> e[0] >> e[1];
	for(int ix=1;ix<=n;ix++)
        for(int iy=1;iy<=m;iy++){
        	g[ix][iy]=1;
		}
            
	for(int i = 0;i < h;i++){
		int x,y;
		cin >> x >> y;
		g[x][y] = 0;
	}
	cout << endl;
	if(g[e[0]][e[1]] != 0){
		dfs(s[0],s[1]);
	}
	cout << ans << endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


