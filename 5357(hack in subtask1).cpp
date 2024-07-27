#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#define NUM  26
#define N    200001
#define NODE 200001
#define ULL  unsigned long long
#define UI   unsigned int

UI idx = 0;
UI chr[NODE][NUM];
UI fail[NODE];
UI nex[NODE];
UI cnt[NODE];
UI flag[NODE];
std::string strs[N];

void insert(std::string patt)
{
    UI cur = 0;
    ULL len = patt.size();
    for (UI i = 0; i < len; i++)
    {
        if (chr[cur][patt[i] - 'a'] == 0)
        {
            chr[cur][patt[i] - 'a'] = ++idx;
        }
        cur = chr[cur][patt[i] - 'a'];
    }
    flag[cur] = 1;
}

void build()
{
    std::queue< UI > qbfs;
    for (UI i = 0; i < NUM; i++)
    {
        if (chr[0][i] != 0)
        {
            qbfs.push(chr[0][i]);
        }
    }
    while (qbfs.size() != 0)
    {
        UI cur = qbfs.front();
        qbfs.pop();
        if (flag[fail[cur]] != 0)
        {
            nex[cur] = fail[cur];
        } else
        {
            nex[cur] = nex[fail[cur]];
        }
        for (UI i = 0; i < NUM; i++)
        {
            UI son = chr[cur][i];
            if (son != 0)
            {
                fail[son] = chr[fail[cur]][i];
                qbfs.push(son);
            } else
            {
                chr[cur][i] = chr[fail[cur]][i];
            }
        }
    }
}

UI find(std::string str)
{
    UI icnt = 0;
    UI cur = 0;
    for (UI k = 0; k < str.size(); k++)
    {
        cur = chr[cur][str[k] - 'a'];
        for (UI j = cur; j != 0; j = nex[j])
        {
            if (flag[j] != 0)
            {
                cnt[j]++;
            }
        }
    }
    return icnt;
}

UI Find(std::string &str)
{
    UI cur = 0;
    ULL len = str.size();
    for (UI i = 0; i < len; i++)
    {
        cur = chr[cur][str[i] - 'a'];
    }
    return cnt[cur];
}

auto main() -> int
{
    UI num;
    std::cin >> num;
    std::string str;
    for (UI i = 0; i < num; i++)
    {
        std::cin >> strs[i];
        insert(strs[i]);
    }
    build();
    std::cin >> str;
    find(str);
    for (UI i = 0; i < num; i++)
    {
        std::cout << Find(strs[i]) << std::endl;
    }
    return 0;
}
