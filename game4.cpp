#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
typedef pair< int, int > pii;
#define xx first
#define yy second
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

struct it {
    int x, y, d;
    it() {}
    it(int x, int y, int d) : x(x), y(y), d(d) {}
};

void setcol(int fc = 15, int bc = 0) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            ((bc & 0x0f) << 4) + (fc & 0x0f));
}

void setpos(short ln = 0, short cl = 0) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {cl, ln});
}

int n, m;
char mp[1005][1005];
int px, py, cx = -1, cy = -1;
bool tpr = 0, tpb = 0;
int scr = 0, cnt = 0;
bool vst[1005][1005];
pii bps[1000005];
int ct = 0;
queue< it > q;
int sx, sy, ex, ey;
int dist;

void gern() {
    ct = 0;
    tpr = 0;
    tpb = 0;
    while (!q.empty())
        q.pop();
    memset(vst, 0, sizeof(vst));
    n = 30, m = 30;
    sx = rand() % n + 1, sy = rand() % m + 1;
    px = sx;
    py = sy;
    ex = rand() % n + 1, ey = rand() % m + 1;
    while (ex == sx && ey == sy)
        ex = rand() % n + 1, ey = rand() % m + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == sx && j == sy)
                mp[i][j] = 'S';
            else if (i == ex && j == ey)
                mp[i][j] = 'E';
            else
                mp[i][j] =
                    "..........................................####################RB"
                        [rand() % 64];
            if (mp[i][j] == 'B')
                bps[++ct] = pii(i, j);
        }
    }
}

void draw() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == px && j == py)
                setcol(0, 10);
            else if (i == cx && j == cy)
                setcol(0, 14);
            else if (mp[i][j] == 'S')
                setcol(0, 2);
            else if (mp[i][j] == 'E')
                setcol(0, 11);
            else if (mp[i][j] == 'R')
                setcol(0, 4);
            else if (mp[i][j] == 'B')
                setcol(0, 1);
            else if (mp[i][j] == '#')
                setcol(0, 8);
            else
                setcol(15, 0);
            cout << "  ";
        }
        cout << endl;
    }
    setcol(15, 0);
    cout << "STEP " << cnt << endl;
    cout << "SCORE " << scr << endl;
    cout << "DIST " << dist << endl;
}

void tp() {
    if (tpr) {
        if (cx == px && mp[cx][cy] != '#') {
            px = cx;
            py = cy;
            cx = -1;
            cy = -1;
            cnt++;
            tpr = 0;
        }
    } else if (tpb) {
        if (mp[cx][cy] == 'B') {
            px = cx;
            py = cy;
            cx = -1;
            cy = -1;
            cnt++;
            tpb = 0;
        }
    } else if (!tpr && mp[px][py] == 'R') {
        cx = px;
        cy = py;
        tpr = 1;
    } else if (!tpb && mp[px][py] == 'B') {
        cx = px;
        cy = py;
        tpb = 1;
    }
}

int bfs() {
    q.push(it(sx, sy, 0));
    bool flag = 0;
    vst[sx][sy] = 1;
    while (!q.empty()) {
        it f = q.front();
        q.pop();
        int x = f.x, y = f.y, d = f.d;
        if (x < 1 || x > n || y < 1 || y > m)
            continue;
        if (x == ex && y == ey) {
            return d;
        }
        if (mp[x][y] == 'R') {
            for (int i = 1; i <= m; i++) {
                if (y != i && mp[x][i] != '#' && !vst[x][i]) {
                    vst[x][i] = 1;
                    q.push(it(x, i, d + 1));
                }
            }
        } else if (mp[x][y] == 'B' && !flag) {
            flag = 1;
            for (int i = 1; i <= ct; i++) {
                if (bps[i].xx != x || bps[i].yy != y ||
                    !vst[bps[i].xx][bps[i].yy]) {
                    vst[bps[i].xx][bps[i].yy] = 1;
                    q.push(it(bps[i].xx, bps[i].yy, d + 1));
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] != '#' &&
                !vst[nx][ny]) {
                vst[nx][ny] = 1;
                q.push(it(nx, ny, d + 1));
            }
        }
    }
    return -1;
}

void play() {
    while (1) {
        setpos();
        draw();
        char c = getch();
        switch (c) {
        case 'w':
            if (!(tpr || tpb) && px > 1 && mp[px - 1][py] != '#')
                px--, cnt++;
            break;
        case 'a':
            if (!(tpr || tpb) && py > 1 && mp[px][py - 1] != '#')
                py--, cnt++;
            break;
        case 's':
            if (!(tpr || tpb) && px < n && mp[px + 1][py] != '#')
                px++, cnt++;
            break;
        case 'd':
            if (!(tpr || tpb) && py < m && mp[px][py + 1] != '#')
                py++, cnt++;
            break;
        case 'i':
            if (tpr || tpb) {
                cx--;
                cx = max(0, cx);
            }
            break;
        case 'j':
            if (tpr || tpb) {
                cy--;
                cy = max(0, cy);
            }
            break;
        case 'k':
            if (tpr || tpb) {
                cx++;
                cx = min(n, cx);
            }
            break;
        case 'l':
            if (tpr || tpb) {
                cy++;
                cy = min(m, cy);
            }
            break;
        case 't': tp(); break;
        case ' ': return;
        }
        if (mp[px][py] == 'E') {
            scr += 100 - (cnt - dist);
            break;
        }
    }
}

int main() {
    system("mode con lines=35 cols=60");
    srand(time(0));
    while (1) {
        system("cls");
        cnt = 0;
        gern();
        dist = bfs();
        if (dist == -1)
            continue;
        play();
    }
    return 0;
}
