#include <bits/stdc++.h>
#define N 401

using std::cin, std::cout, std::queue;

struct point
{
    int step;
    int x, y;
};

int setx;
int sety;
int width;
int height;
int arr[N][N];
int way[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                 {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

void bfs()
{
    queue< point > que;
    que.push({0, setx, sety});
    arr[setx][sety] = 0;
    while (!que.empty())
    {
        point tmp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++)
        {
            int tmpx = tmp.x + way[i][0];
            int tmpy = tmp.y + way[i][1];
            if (tmpx > 0 && tmpy > 0 && tmpx <= width && tmpy <= height &&
                arr[tmpx][tmpy] == -1)
            {
                arr[tmpx][tmpy] = tmp.step + 1;
                que.push({tmp.step + 1, tmpx, tmpy});
            }
        }
    }
}

int main()
{
    cin >> width >> height;
    cin >> setx >> sety;
    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            arr[i][j] = -1;
        }
    }
    bfs();
    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
