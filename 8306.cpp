#include <iostream>
#include <string>
#define N    3000001
#define M    100001
#define BASE 122

using namespace std;

int ncnt;
int tree[N][BASE];
int cnt[N];
int res[N];
int pos[N];
string strs[M];

void insert(const string &str, int idt)
{
    int cur = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (tree[cur][str[i]] == 0)
        {
            tree[cur][str[i]] = ++ncnt;
        }
        cur = tree[cur][str[i]];
    }
    pos[idt] = cur;
    cnt[cur]++;
}

void find(string str)
{
    int cur = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (cnt[cur] != 0)
        {
            res[cur]++;
        }
        if (tree[cur][str[i]] == 0)
        {
            return;
        }
        cur = tree[cur][str[i]];
    }
    if (cnt[cur] != 0)
    {
        res[cur]++;
    }
}

int main()
{
    int num;
    int qcnt;
    int test;
    cin >> test;
    for (int j = 1; j <= test; j++)
    {
        for (int i = 0; i <= ncnt; i++)
        {
            for (int j = 0; j < BASE; j++)
            {
                tree[i][j] = 0;
            }
            cnt[i] = 0;
            res[i] = 0;
            pos[i] = 0;
        }
        ncnt = 0;
        cin >> num >> qcnt;
        for (int i = 1; i <= num; i++)
        {
            cin >> strs[i];
        }
        for (int i = 1; i <= qcnt; i++)
        {
            string tmp;
            cin >> tmp;
            insert(tmp, i);
        }
        for (int i = 1; i <= num; i++)
        {
            find(strs[i]);
        }
        for (int i = 1; i <= qcnt; i++)
        {
            cout << res[pos[i]] << endl;
        }
    }
    return 0;
}
