#include <iostream>
#include <queue>
#include <string>
#define N    200001
#define BASE 26

int trie[N][BASE];
int fail[N];
int inner[N];
int ans[N];
int flag[N];
int rev[N];
int vis[N];

int cnt = 1;

void insert(const std::string &tmp, int num)
{
    int cur = 1;
    for (char chi : tmp)
    {
        int chr = chi - 'a';
        if (trie[cur][chr] == 0)
        {
            trie[cur][chr] = ++cnt;
        }
        cur = trie[cur][chr];
    }
    if (flag[cur] == 0)
    {
        flag[cur] = num;
    }
    rev[num] = flag[cur];
}

void build()
{
    std::queue< int > nodes;
    for (int i = 0; i < BASE; i++)
    {
        trie[0][i] = 1;
    }
    nodes.push(1);
    while (!nodes.empty())
    {
        int cur = nodes.front();
        nodes.pop();
        for (int i = 0; i < BASE; i++)
        {
            int son = trie[cur][i];
            if (son != 0)
            {
                fail[son] = trie[fail[cur]][i];
                inner[trie[fail[cur]][i]]++;
                nodes.push(son);
            } else
            {
                trie[cur][i] = trie[fail[cur]][i];
            }
        }
    }
}

void query(const std::string &str)
{
    int cur = 1;
    for (char iii : str)
    {
        cur = trie[cur][iii - 'a'];
        ans[cur]++;
    }
}

void topu()
{
    std::queue< int > topubfs;
    for (int i = 1; i <= cnt; i++)
    {
        if (inner[i] == 0)
        {
            topubfs.push(i);
        }
    }
    while (!topubfs.empty())
    {
        int cur = topubfs.front();
        topubfs.pop();
        vis[flag[cur]] = ans[cur];
        int Fail = fail[cur];
        ans[Fail] += ans[cur];
        if (--inner[Fail] == 0)
        {
            topubfs.push(Fail);
        }
    }
}

int main()
{
    int num;
    std::string str;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        insert(tmp, i);
    }
    build();
    std::cin >> str;
    query(str);
    topu();
    for (int i = 1; i <= num; i++)
    {
        std::cout << vis[rev[i]] << std::endl;
    }
    return 0;
}
