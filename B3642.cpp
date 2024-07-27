#include <iostream>
#define N 1000001

using std::cin, std::cout, std::endl;

struct node
{
    int ls, rs;
} tree[N];

void dfsin(int cur)
{
    if (cur == 0)
    {
        return;
    }
    dfsin(tree[cur].ls);
    cout << cur << " ";
    dfsin(tree[cur].rs);
}

void dfspo(int cur)
{
    if (cur == 0)
    {
        return;
    }
    dfspo(tree[cur].ls);
    dfspo(tree[cur].rs);
    cout << cur << " ";
}

void dfspr(int cur)
{
    if (cur == 0)
    {
        return;
    }
    cout << cur << " ";
    dfspr(tree[cur].ls);
    dfspr(tree[cur].rs);
}

int main()
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> tree[i].ls >> tree[i].rs;
    }
    dfspr(1);
    cout << endl;
    dfsin(1);
    cout << endl;
    dfspo(1);
    cout << endl;
    return 0;
}
