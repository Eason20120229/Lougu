#include <iostream>
#define N 121
#define M 81

using namespace std;

int inn;
int inm;
int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool enter[N][M];
bool vis[N][M];
int walk[N * M][2];
bool flag;

void dfs(int posx, int posy, int cur)
{
    walk[cur][0] = posx;
    walk[cur][1] = posy;
    if (posx == inn && posy == inm)
    {
        flag = true;
        for (int i = 1; i <= cur; i++)
        {
            cout << walk[i][0] << " " << walk[i][1] << endl;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int tmx = posx + way[i][0];
        int tmy = posy + way[i][1];
        if (tmx > 0 && tmy > 0 && tmx <= inn && tmy <= inm && !vis[tmx][tmy] &&
            !enter[tmx][tmy])
        {
            vis[tmx][tmy] = true;
            dfs(tmx, tmy, cur + 1);
            if (flag)
            {
                return;
            }
        }
    }
}

int main()
{
    cin >> inn >> inm;
    for (int i = 1; i <= inn; i++)
    {
        for (int j = 1; j <= inm; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == '*')
            {
                enter[i][j] = true;
            }
        }
    }
    dfs(1, 1, 1);
    return 0;
}
