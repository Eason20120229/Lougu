#include <iostream>

using namespace std;

char g[101][101];
char g2[101][101];
char a[11] = "yizhong";
int xy[8][2] = {{1,0},{1,-1},{1,1},{-1,0},{-1,-1},{-1,1},{0,1},{0,-1}};

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cin >> g[i][j];
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            if(g[i][j] == a[0]){
                int l = 0;
                for(int k = 0;k < 8;k++){
                    int u = 0,f = 0;
                    for(int x = i,y = j;u < 7;x += xy[k][0],y += xy[k][1],u++){
                        if(g[x][y] != a[u] || !(x > 0 && y > 0 && x <= n && y <= n)) f = 1;
                    }
                    if(f) continue;
                    u = 0;
                    for(int x = i,y = j;u < 7;x += xy[k][0],y += xy[k][1],u++){
                        g2[x][y] = a[u];
                    }
                    l = 1;
                }
                if(!l) g2[i][j] = '*';
            }else if(!g2[i][j]) g2[i][j] = '*';
        }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++)
            cout << g2[i][j];
        cout << endl;
    }
    return 0;
}
