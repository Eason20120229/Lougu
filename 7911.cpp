#include <iostream>
#include <string>
#include <utility>
#define N    256
#define M    65536
#define BASE 10
#define NM   10001

struct mystring
{
    std::string str;
    int pos;
};

struct myint
{
    int a, b, c, d, e;
};

int cnt = 0;
myint server[NM];

bool isNum(char chr)
{
    return chr <= '9' && chr >= '0';
}

int readNum(mystring &str)
{
    if (str.pos >= str.str.size() ||
        (isNum(str.str[str.pos + 1]) && str.str[0] == '0') ||
        !isNum(str.str[str.pos]))
    {
        return -1;
    }
    int number = 0;
    while (str.pos < str.str.size() && isNum(str.str[str.pos]))
    {
        number = number * BASE + (str.str[str.pos] - '0');
        str.pos++;
    }
    return number;
}

bool check(std::string str, int arr[])
{
    mystring tmp = {std::move(str), 0};
    int tnum = readNum(tmp);
    if (tnum >= N || tnum < 0 || tmp.str[tmp.pos] != '.')
    {
        return false;
    }
    tmp.pos++;
    arr[1] = tnum;
    tnum = readNum(tmp);
    if (tnum >= N || tnum < 0 || tmp.str[tmp.pos] != '.')
    {
        return false;
    }
    arr[2] = tnum;
    tmp.pos++;
    tnum = readNum(tmp);
    if (tnum >= N || tnum < 0 || tmp.str[tmp.pos] != '.')
    {
        return false;
    }
    arr[3] = tnum;
    tmp.pos++;
    tnum = readNum(tmp);
    if (tnum >= N || tnum < 0 || tmp.str[tmp.pos] != ':')
    {
        return false;
    }
    arr[4] = tnum;
    tmp.pos++;
    tnum = readNum(tmp);
    arr[5] = tnum;
    if (tmp.pos < tmp.str.size())
    {
        return false;
    }
    return tnum < M && tnum != -1;
}

auto main() -> int
{
    int num;
    scanf("%d", &num);
    while (num-- != 0)
    {
        std::string address;
        std::string opt;
        std::cin >> opt >> address;
        if (opt[0] == 'S')
        {
            int arr[BASE];
            if (!check(address, arr))
            {
                std::cout << "ERR" << "\n";
                continue;
            }
            bool flag = true;
            for (int i = 1; i <= cnt; i++)
            {
                if (server[i].a == arr[1] && server[i].b == arr[2] &&
                    server[i].c == arr[3] && server[i].d == arr[4] &&
                    server[i].e == arr[5])
                {
                    flag = false;
                }
            }
            if (!flag)
            {
                std::cout << "FAIL" << "\n";
            } else
            {
                std::cout << "OK" << "\n";
                server[++cnt].a = arr[1];
                server[cnt].b = arr[2];
                server[cnt].c = arr[3];
                server[cnt].d = arr[4];
                server[cnt].e = arr[5];
            }
        } else
        {
            int arr[BASE];
            if (!check(address, arr))
            {
                std::cout << "ERR" << "\n";
                continue;
            }
            bool flag = true;
            int idt = 0;
            for (int i = 1; i <= cnt; i++)
            {
                if (server[i].a == arr[1] && server[i].b == arr[2] &&
                    server[i].c == arr[3] && server[i].d == arr[4] &&
                    server[i].e == arr[5])
                {
                    flag = false;
                    idt = i;
                }
            }
            if (flag)
            {
                std::cout << "FAIL" << "\n";
            } else
            {
                std::cout << idt << "\n";
            }
        }
    }
    // for (int i = 1; i <= cnt; i++)
    // {
    //     std::cout << server[i].a << " " << server[i].b << " " << server[i].c
    //               << " " << server[i].d << " " << server[i].e << std::endl;
    // }
    return 0;
}
