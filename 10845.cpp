#include <iostream>
#define N         200001
#define lowbit(x) ((-x) & x)

using std::cin, std::cout, std::max;

struct node
{
    int l, r;
};

int num;
int dparr[N];
node input[N];
int tree[N][N];

void update(int value,int right,int rnode)
{
    for(int i = right;i <= num;i += lowbit(i))
}

int main()
{
    int ans = 0;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int tml;
        int tmr;
        cin >> tml >> tmr;
        input[i].l = i - tml;
        if (input[i].l < 1)
        {
            input[i].l = 1;
        }
        input[i].r = i + tmr;
        if (input[i].r > num)
        {
            input[i].r = num;
        }
    }
    for (int i = 1; i <= num; i++)
    {
        ans = max(ans, dparr[i]);
    }
    cout << ans;
    return 0;
}
