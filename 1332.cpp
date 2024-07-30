/*

6 3 2 2
1 1
4 2
2 2
6 3
:2
3

5 4 2 4
1 2
5 3
2 3
3 1
4 2
4 4
:2
3
2
2

3 3 1 4
2 2
1 1
1 3
3 1
3 3
:2
2
2
2

2 9 2 4
1 2
2 8
2 2
1 5
2 5
1 9
:1
3
3
2

*/

#include <cstdio>
#include <queue>
#define N 501
#define M 100001

struct person
{
    int x;
    int y;
    int day;
};

int rows, cols;
int ruler[N][N];
int ans[M];
int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[N][N];
std::queue< person > qbfs;

auto check(int tmpx, int tmpy) -> bool
{
    return tmpx > 0 && tmpy > 0 && tmpx <= rows && tmpy <= cols;
}

void bfs()
{
    while (!qbfs.empty())
    {
        person tmp = qbfs.front();
        qbfs.pop();
        if (ruler[tmp.x][tmp.y] != 0)
        {
            ans[ruler[tmp.x][tmp.y]] = tmp.day;
        }
        for (auto &idt : way)
        {
            int tmpx = tmp.x + idt[0];
            int tmpy = tmp.y + idt[1];
            if (check(tmpx, tmpy) && !vis[tmpx][tmpy])
            {
                vis[tmpx][tmpy] = true;
                qbfs.push({tmpx, tmpy, tmp.day + 1});
            }
        }
    }
}

auto main() -> int
{
    int num;
    int cnt;
    scanf("%d %d %d %d", &rows, &cols, &num, &cnt);
    for (int i = 1; i <= num; i++)
    {
        int row;
        int col;
        scanf("%d %d", &row, &col);
        qbfs.push({row, col, 0});
        vis[row][col] = true;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int row;
        int col;
        scanf("%d %d", &row, &col);
        ruler[row][col] = i;
    }
    bfs();
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
