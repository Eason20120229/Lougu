// 键盘扫描码（重点）
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

// 地图大小
const int n = 9, m = 9;

// 地图
char mp[n + 1][m + 2] = {
    "",            //
    " *********",  //
    " *.......*",  //
    " *...P...*",  //
    " *.......*",  //
    " *.......*",  //
    " *.......*",  //
    " *...G...*",  //
    " *.......*",  //
    " *********",  //
};

// 玩家当前位置
int px = 3, py = 5, gx = 7, gy = 5;

// 输出地图
void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 'P') {
                cout << "\033[01;33mP\033[0m";
            } else if (mp[i][j] == 'G') {
                cout << "\033[01;34mB\033[0m";
            } else if (mp[i][j] == '*') {
                cout << "\033[01;35m*\033[0m";
            } else {
                cout << mp[i][j];
            }
        }
        cout << '\n';
    }
}

void input() {
    int opt;
    if (_kbhit() == 1) {
        opt = _getch();
        switch (opt) {
        case 'w':
            if (mp[px - 1][py] == '.') {
                mp[px][py] = '.';
                px--;
                mp[px][py] = 'P';
            }
            break;
        case 'a':
            if (mp[px][py - 1] == '.') {
                mp[px][py] = '.';
                py--;
                mp[px][py] = 'P';
            }
            break;
        case 's':
            if (mp[px + 1][py] == '.') {
                mp[px][py] = '.';
                px++;
                mp[px][py] = 'P';
            }
            break;
        case 'd':
            if (mp[px][py + 1] == '.') {
                mp[px][py] = '.';
                py++;
                mp[px][py] = 'P';
            }
            break;
        case 224:
            opt = _getch();
            switch (opt) {
            // 上
            case 72:
                if (mp[gx - 1][gy] == '.') {
                    mp[gx][gy] = '.';
                    gx--;
                    mp[gx][gy] = 'G';
                }
                break;
            // 左
            case 75:
                if (mp[gx][gy - 1] == '.') {
                    mp[gx][gy] = '.';
                    gy--;
                    mp[gx][gy] = 'G';
                }
                break;
            // 下
            case 80:
                if (mp[gx + 1][gy] == '.') {
                    mp[gx][gy] = '.';
                    gx++;
                    mp[gx][gy] = 'G';
                }
                break;
            // 右
            case 77:
                if (mp[gx][gy + 1] == '.') {
                    mp[gx][gy] = '.';
                    gy++;
                    mp[gx][gy] = 'G';
                }
                break;
            }
        }
    }
}

auto main() -> int {
    while (true) {
        system("cls");
        output();
        input();
    }
    return 0;
}
