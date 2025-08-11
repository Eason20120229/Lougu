#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

char a[70][7];
void writemap() {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j < 7; j++) {
            a[i][j] = '.';
        }
    }
    for (int i = 0; i < 7; i++)
        a[0][i] = '!';
    for (int i = 3; i < 65; i++) {
        if (i % 3 == 0) {
            int t = rand() % 4 + 1;
            a[i][0] = '|';
            a[i][3] = '|';
            a[i][6] = '|';
            if (t == 1) {
                a[i][1] = '+';
            }
            if (t == 2) {
                a[i][1] = '-';
            }
            if (t == 3) {
                a[i][1] = '*';
            }
            if (t == 4) {
                a[i][1] = '/';
            }
            a[i][2] = '0';
            a[i][2] += rand() % 9 + 1;
            int d = rand() % 4 + 1;
            if (d == 1) {
                a[i][4] = '+';
            }
            if (d == 2) {
                a[i][4] = '-';
            }
            if (d == 3) {
                a[i][4] = '*';
            }
            if (d == 4) {
                a[i][4] = '/';
            }
            a[i][5] = '0';
            a[i][5] += rand() % 9 + 1;
        } else {
            for (int j = 0; j < 7; j++)
                a[i][j] = '.';
        }
    }
    for (int i = 65; i <= 70; i++) {
        for (int j = 0; j < 7; j++) {
            a[i][j] = '.';
        }
    }
}
bool canmove(int y) {
    if (y < 0 || y >= 7)
        return 0;
    return 1;
}

int main() {
    srand(time(NULL));
    string s = "startgame";
    while (s == "startgame") {
        int x = 68, y = 3;
        cout << "startgame/exit" << endl;
        cin >> s;
        system("cls");
        if (s != "start")
            break;
        writemap();
        int Score = 0;
        // 高精度计时器
        auto last_time = chrono::steady_clock::now();
        const int scroll_interval = 500;
        int scroll_counter = 0;
        while (a[x][y] != '!') {
            auto current_time = chrono::steady_clock::now();
            auto elapsed = chrono::duration_cast< chrono::milliseconds >(
                               current_time - last_time)
                               .count();

            // 实时响应
            if (_kbhit()) {
                int k = _getch();
                switch (k) {
                case 'a':
                    if (canmove(y - 1))
                        y--;
                    break;
                case 'd':
                    if (canmove(y + 1))
                        y++;
                    break;
                }
            }
            if (elapsed >= scroll_interval) {
                last_time = current_time;
                scroll_counter++;
                if (scroll_counter % 2 == 0) {
                    system("cls");
                    for (int i = x - 4; i <= x + 1; i++) {
                        for (int j = 0; j < 7; j++) {
                            if (i != x || j != y)
                                cout << a[i][j];
                            else
                                cout << "^";
                        }
                        cout << endl;
                    }
                    cout << "Score:" << Score << endl;

                    x--;
                    if (a[x][y] >= '0' && a[x][y] <= '9') {
                        if (a[x][y - 1] == '+')
                            Score += a[x][y] - '0';
                        if (a[x][y - 1] == '-')
                            Score -= a[x][y] - '0';
                        if (a[x][y - 1] == '*')
                            Score *= a[x][y] - '0';
                        if (a[x][y - 1] == '/')
                            Score /= a[x][y] - '0';
                    }
                    if (a[x][y] == '+' || a[x][y] == '-' || a[x][y] == '*' ||
                        a[x][y] == '/') {
                        if (a[x][y] == '+')
                            Score += a[x][y + 1] - '0';
                        if (a[x][y] == '-')
                            Score -= a[x][y + 1] - '0';
                        if (a[x][y] == '*')
                            Score *= a[x][y + 1] - '0';
                        if (a[x][y] == '/')
                            Score /= a[x][y + 1] - '0';
                    }
                }
            }
            Sleep(10);  // 可能会更好一点
        }
        cout << "Your Score:" << Score << endl;
    }
    return 0;
}
