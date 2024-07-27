#include <iostream>
#include <string>
#define N 11

using std::cin, std::cout, std::string;

int arr[N];
int gra[N][N];

bool checkline(int value, int lin)
{
    return gra[lin][1] == value && gra[lin][2] == value && gra[lin][3] == value;
}

bool checkcol(int value, int col)
{
    return gra[1][col] == value && gra[2][col] == value && gra[3][col] == value;
}

bool checkf(int value)
{
    return (gra[1][1] == value && gra[2][2] == value && gra[3][3] == value) ||
           (gra[1][3] == value && gra[2][2] == value && gra[3][1] == value);
}

bool check(int value)
{
    return checkline(value, 1) || checkline(value, 2) || checkline(value, 3) ||
           checkcol(value, 1) || checkcol(value, 2) || checkcol(value, 3) ||
           checkf(value);
}

int main()
{
    string str;
    cin >> str;
    for (int i = 1; i <= str.size(); i++)
    {
        int col;
        int row;
        arr[i] = str[i - 1] - '0';
        col = arr[i] % 3;
        if (col == 0)
        {
            col += 3;
        }
        row = (arr[i] - col) / 3 + 1;
        gra[row][col] = i % 2 == 1 ? 1 : 2;
        if (check(1))
        {
            cout << "xiaoa wins.";
            return 0;
        }
        if (check(2))
        {
            cout << "uim wins.";
            return 0;
        }
    }
    cout << "drew.";
    return 0;
}
