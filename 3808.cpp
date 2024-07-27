#include <iostream>
#include <queue>
#include <string>
#define N    1000001
#define BASE 26

struct node
{
    int fail;
    int son[BASE];
    int cnt;
} trie[N];

int cnt = 1;

void insert(const std::string &tmp)
{
    int cur = 0;
    for (char chi : tmp)
    {
        int chr = chi - 'a';
        if (trie[cur].son[chr] == 0)
        {
            trie[cur].son[chr] = cnt++;
        }
        cur = trie[cur].son[chr];
    }
    trie[cur].cnt++;
}

void build()
{
    std::queue< int > nodes;
    for (int iint : trie[0].son)
    {
        if (iint != 0)
        {
            nodes.push(iint);
        }
    }
    while (!nodes.empty())
    {
        int cur = nodes.front();
        nodes.pop();
        for (int i = 0; i < BASE; i++)
        {
            int son = trie[cur].son[i];
            if (son != 0)
            {
                trie[son].fail = trie[trie[cur].fail].son[i];
                nodes.push(son);
            } else
            {
                trie[cur].son[i] = trie[trie[cur].fail].son[i];
            }
        }
    }
}

int query(const std::string &str)
{
    int ans = 0;
    int cur = 0;
    for (char iii : str)
    {
        cur = trie[cur].son[iii - 'a'];
        for (int j = cur; j != 0 && trie[j].cnt != -1; j = trie[j].fail)
        {
            ans += trie[j].cnt;
            trie[j].cnt = -1;
        }
    }
    return ans;
}

int main()
{
    int num;
    std::string str;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        insert(tmp);
    }
    build();
    std::cin >> str;
    std::cout << query(str);
    return 0;
}
