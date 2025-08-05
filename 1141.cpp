#include <iostream>
#define N 1001
#define M 100001

using namespace std;

int ans;
int strx;
int stry;
int nnum;
int mnum;
char cmap[N][N];
int vis[N][N];
pair< int, int > res[N][N];
bool book[N][N];
int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int curx, int cury, char chr)
{
    ans++;
    res[curx][cury].first = strx;
    res[curx][cury].second = stry;
    for (int i = 0; i < 4; i++)
    {
        int tmx = curx + way[i][0];
        int tmy = cury + way[i][1];
        if (tmx > 0 && tmy > 0 && tmx <= nnum && tmy <= nnum &&
            cmap[tmx][tmy] != chr && !book[tmx][tmy])
        {
            book[tmx][tmy] = true;
            dfs(tmx, tmy, cmap[tmx][tmy]);
        }
    }
}

int main()
{
    cin >> nnum >> mnum;
    for (int i = 1; i <= nnum; i++)
    {
        for (int j = 1; j <= nnum; j++)
        {
            cin >> cmap[i][j];
        }
    }
    for (int i = 1; i <= nnum; i++)
    {
        for (int j = 1; j <= nnum; j++)
        {
            if (!book[i][j])
            {
                strx = i;
                stry = j;
                book[i][j] = true;
                dfs(i, j, cmap[i][j]);
                vis[i][j] = ans;
                ans = 0;
            }
        }
    }
    for (int i = 1; i <= mnum; i++)
    {
        int stx;
        int sty;
        cin >> stx >> sty;
        cout << vis[res[stx][sty].first][res[stx][sty].second] << endl;
    }
    return 0;
}
