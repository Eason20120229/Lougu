#include <iostream>
#include <string>
#define N    1000001
#define BASE 26

using namespace std;

int cnt;
int tree[N][BASE];
int ans[N];

void insert(const string &str)
{
    int cur = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (tree[cur][str[i] - 'a'] == 0)
        {
            tree[cur][str[i] - 'a'] = ++cnt;
        }
        cur = tree[cur][str[i] - 'a'];
    }
    ans[cur]++;
}

int find(string str)
{
    int cur = 0;
    int ret = 0;
    for (int i = 0; i < str.size(); i++)
    {
        ret += ans[cur];
        if (tree[cur][str[i] - 'a'] == 0)
        {
            return ret;
        }
        cur = tree[cur][str[i] - 'a'];
    }
    ret += ans[cur];
    return ret;
}

int main()
{
    int num;
    int qcnt;
    cin >> num >> qcnt;
    for (int i = 1; i <= num; i++)
    {
        string tmp;
        cin >> tmp;
        insert(tmp);
    }
    for (int i = 1; i <= qcnt; i++)
    {
        string tmp;
        cin >> tmp;
        cout << find(tmp) << endl;
    }
    return 0;
}
