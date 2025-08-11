#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

// 地图大小
const int n = 9, m = 9;

// 当前历史
int cnt = 1;

// 最后的历史
int mxcnt = 1;

// 最多历史数和关卡数目
const int h = 10001, mxpro = 2;

// 当前关卡
int curpro = 0;

// 地图，第一维表示关卡数，第二维表示当前关卡历史
char mp[mxpro][h][n + 1][m + 2] = {{{},
                                    {
                                        "",
                                        " *********",
                                        " *.......*",
                                        " *.......*",
                                        " *..B....*",
                                        " *...P...*",
                                        " *.......*",
                                        " *...B...*",
                                        " *.......*",
                                        " *********",
                                    }},
                                   {{},
                                    {
                                        "",
                                        " *********",
                                        " *.......*",
                                        " *...B...*",
                                        " *.......*",
                                        " *.B.P...*",
                                        " *.......*",
                                        " *.......*",
                                        " *.......*",
                                        " *********",
                                    }}};

// 玩家当前位置，第一维表示关卡数，第二维表示当前关卡历史
int curx[mxpro][h] = {{0, 5}, {0, 5}}, cury[mxpro][h] = {{0, 5}, {0, 5}};

// 目标位置，第一维表示关卡数
vector< pair< int, int > > fins[mxpro] = {{{6, 6}, {4, 5}}, {{6, 6}, {4, 5}}};

// 查询向量中是否含有此元素
auto fd(vector< pair< int, int > > v, pair< int, int > p) -> bool {
    return std::any_of(v.begin(), v.end(), [&](pair< int, int > i) {
        return i == p;
    });
}

// 输出地图
void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[curpro][cnt][i][j] == 'B' && fd(fins[curpro], {i, j})) {
                cout << "\033[04;32m" << mp[curpro][cnt][i][j] << "\033[0m";
            } else if (fd(fins[curpro], {i, j}) &&
                       mp[curpro][cnt][i][j] == 'P') {
                cout << "\033[04;31m" << mp[curpro][cnt][i][j] << "\033[0m";
            } else if (fd(fins[curpro], {i, j})) {
                cout << "_";
            } else if (mp[curpro][cnt][i][j] == 'P') {
                cout << "\033[01;33mP\033[0m";
            } else if (mp[curpro][cnt][i][j] == 'B') {
                cout << "\033[01;34mB\033[0m";
            } else if (mp[curpro][cnt][i][j] == '*') {
                cout << "\033[01;35m*\033[0m";
            } else {
                cout << mp[curpro][cnt][i][j];
            }
        }
        cout << '\n';
    }
}

// 更新玩家位置
bool updPlayer(int opt) {
    // 新增历史
    mxcnt = ++cnt;
    memcpy(mp[curpro][cnt], mp[curpro][cnt - 1], sizeof mp[curpro][cnt]);
    curx[curpro][cnt] = curx[curpro][cnt - 1];
    cury[curpro][cnt] = cury[curpro][cnt - 1];

    int tx = curx[curpro][cnt];
    int ty = cury[curpro][cnt];
    if (opt == 'w') {
        // 找空白位置
        while (mp[curpro][cnt][tx][ty] != '.' &&
               mp[curpro][cnt][tx][ty] != '*') {
            tx--;
        }
        if (mp[curpro][cnt][tx][ty] == '.') {
            // 更新玩家及箱子位置
            for (int i = tx; i < curx[curpro][cnt]; i++) {
                mp[curpro][cnt][i][ty] = mp[curpro][cnt][i + 1][ty];
            }
            mp[curpro][cnt][curx[curpro][cnt]][cury[curpro][cnt]] = '.';
            return true;
        }
    }
    if (opt == 'a') {
        // 找空白位置
        while (mp[curpro][cnt][tx][ty] != '.' &&
               mp[curpro][cnt][tx][ty] != '*') {
            ty--;
        }
        if (mp[curpro][cnt][tx][ty] == '.') {
            // 更新玩家及箱子位置
            for (int j = ty; j < cury[curpro][cnt]; j++) {
                mp[curpro][cnt][tx][j] = mp[curpro][cnt][tx][j + 1];
            }
            mp[curpro][cnt][curx[curpro][cnt]][cury[curpro][cnt]] = '.';
            return true;
        }
    }
    if (opt == 's') {
        // 找空白位置
        while (mp[curpro][cnt][tx][ty] != '.' &&
               mp[curpro][cnt][tx][ty] != '*') {
            tx++;
        }
        if (mp[curpro][cnt][tx][ty] == '.') {
            // 更新玩家及箱子位置
            for (int i = tx; i > curx[curpro][cnt]; i--) {
                mp[curpro][cnt][i][ty] = mp[curpro][cnt][i - 1][ty];
            }
            mp[curpro][cnt][curx[curpro][cnt]][cury[curpro][cnt]] = '.';
            return true;
        }
    }
    if (opt == 'd') {
        // 找空白位置
        while (mp[curpro][cnt][tx][ty] != '.' &&
               mp[curpro][cnt][tx][ty] != '*') {
            ty++;
        }
        if (mp[curpro][cnt][tx][ty] == '.') {
            // 更新玩家及箱子位置
            for (int j = ty; j > cury[curpro][cnt]; j--) {
                mp[curpro][cnt][tx][j] = mp[curpro][cnt][tx][j - 1];
            }
            mp[curpro][cnt][curx[curpro][cnt]][cury[curpro][cnt]] = '.';
            return true;
        }
    }
    return false;  // 找不到空白
}

// 判断游戏是否结束
auto isWin() -> bool {
    return !std::any_of(fins[curpro].begin(), fins[curpro].end(),
                        [&](pair< int, int > i) {
                            return mp[curpro][cnt][i.first][i.second] != 'B';
                        });
}

void input() {
    int opt;
    if (_kbhit() == 1) {
        opt = _getch();
        switch (opt) {
        case 'w':
            if (updPlayer(opt)) {
                curx[curpro][cnt]--;
            }
            break;
        case 'a':
            if (updPlayer(opt)) {
                cury[curpro][cnt]--;
            }
            break;
        case 's':
            if (updPlayer(opt)) {
                curx[curpro][cnt]++;
            }
            break;
        case 'd':
            if (updPlayer(opt)) {
                cury[curpro][cnt]++;
            }
            break;
        // 回到上个历史
        case 'z':
            if (cnt > 1) {
                cnt--;
            }
            break;
        // 切换到下个历史
        case 'x':
            if (cnt < mxcnt) {
                cnt++;
            }
            break;
        // 重置地图
        case 'r':
            cnt++;
            memcpy(mp[curpro][cnt], mp[curpro][1], sizeof mp[curpro][cnt]);
            curx[curpro][cnt] = curx[curpro][1];
            cury[curpro][cnt] = cury[curpro][1];
            break;
        }
    }
}

auto main() -> int {
    while (true) {
        system("cls");
        output();
        if (isWin()) {
            // 切换关卡
            cout << "You Win!\n";
            cnt = 1;
            curpro++;
            if (curpro >= mxpro) {
                break;
            }
            system("pause");
            continue;
        }
        input();
    }
    return 0;
}
