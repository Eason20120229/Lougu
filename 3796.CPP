#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define NUM  26
#define N    201
#define NODE 100001
#define ULL  unsigned long long
#define UI   unsigned int

UI idx = 0;
UI chr[NODE][NUM];
UI fail[NODE];
UI cnt[NODE];
UI flag[NODE];
std::string strs[N];
std::vector< std::string > ans;

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
        for (UI j = cur; j != 0 && cnt[j] != -1; j = fail[j])
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

int main()
{
    UI num;
    std::cin >> num;
    while (num != 0)
    {
        while (ans.size() != 0)
        {
            ans.pop_back();
        }
        std::memset(chr, 0, sizeof(chr));
        std::memset(flag, 0, sizeof(flag));
        std::memset(fail, 0, sizeof(fail));
        std::memset(cnt, 0, sizeof(cnt));
        idx = 0;
        std::string str;
        for (UI i = 0; i < num; i++)
        {
            std::cin >> strs[i];
            insert(strs[i]);
        }
        build();
        std::cin >> str;
        find(str);
        ans.push_back(strs[0]);
        UI mxcnt = Find(strs[0]);
        for (UI i = 1; i < num; i++)
        {
            UI tmp = Find(strs[i]);
            if (tmp > mxcnt)
            {
                while (ans.size() != 0)
                {
                    ans.pop_back();
                }
                ans.push_back(strs[i]);
                mxcnt = tmp;
            } else if (tmp == mxcnt)
            {
                ans.push_back(strs[i]);
            }
        }
        std::cout << mxcnt << std::endl;
        for (UI i = 0; i < ans.size(); i++)
        {
            std::cout << ans[i] << std::endl;
        }
        std::cin >> num;
    }
    return 0;
}
