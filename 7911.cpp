#include <iostream>
#include <string>
#include <utility>
#define N    256
#define M    65536
#define LEN  10
#define BASE 10
#define H                                 \
    {                                     \
        N - 1, N - 1, N - 1, N - 1, M - 1 \
    }

using std::cout, std::cin, std::ios, std::string, std::endl;

struct mystr
{
    string cur;
    int point;
};

struct
{
    int arr[LEN];
    int id;
} server[M];

int cnt;
char cur[LEN] = {'.', '.', '.', ':'};
int arr[LEN];
int high[LEN] = H;

bool checkn(char chr)
{
    return chr >= '0' && chr <= '9';
}

auto readn(mystr &str, char cur, int high) -> int
{
    bool flag = str.cur[str.point] == '0';
    int ans = 0;
    int len = 0;
    if (!checkn(str.cur[str.point]))
    {
        return -1;
    }
    while (checkn(str.cur[str.point]) && str.point < str.cur.size())
    {
        ans = ans * BASE + str.cur[str.point] - '0';
        str.point++;
        if (ans > high)
        {
            return -1;
        }
        len++;
    }
    if ((str.point < str.cur.size() && str.cur[str.point] != cur) ||
        (flag && (ans != 0 || len > 1)))
    {
        return -1;
    }
    str.point++;
    return ans;
}

bool check(string adr)
{
    mystr add = {std::move(adr), 0};
    for (int i = 0; i <= 4; i++)
    {
        arr[i] = readn(add, cur[i], high[i]);
        if (arr[i] == -1)
        {
            return false;
        }
    }
    return add.point - 1 == add.cur.size();
}

int main()
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int pos = -1;
        string opt;
        string adr;
        cin >> opt >> adr;
        if (!check(adr))
        {
            cout << "ERR" << endl;
            continue;
        }
        for (int i = 1; i <= cnt; i++)
        {
            bool tmp = true;
            for (int j = 0; j <= 4; j++)
            {
                tmp &= arr[j] == server[i].arr[j];
            }
            if (tmp)
            {
                pos = i;
                break;
            }
        }
        if (opt[0] == 'S')
        {
            if (pos == -1)
            {
                server[++cnt] = {{arr[0], arr[1], arr[2], arr[3], arr[4]}, i};
                cout << "OK" << endl;
            } else
            {
                cout << "FAIL" << endl;
            }
        } else
        {
            if (pos != -1)
            {
                cout << server[pos].id << endl;
            } else
            {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}
