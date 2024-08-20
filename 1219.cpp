#include <iostream>
#define N 14

using namespace std;

int num;
int ans = 0;
bool line1[N];
bool line2[2 * N];
bool line3[2 * N];
int save[N];

void dfs(int posx)
{
    if (posx == num + 1)
    {
        ans++;
        if (ans <= 3)
        {
            for (int i = 1; i <= num; i++)
            {
                cout << save[i] << " ";
            }
            cout << endl;
        }
    }
    for (int i = 1; i <= num; i++)
    {
        if (!line1[i] && !line2[posx - i + num] && !line3[posx + i])
        {
            line1[i] = true;
            line2[posx - i + num] = true;
            line3[posx + i] = true;
            save[posx] = i;
            dfs(posx + 1);
            line1[i] = false;
            line2[posx - i + num] = false;
            line3[posx + i] = false;
        }
    }
}

int main()
{
    cin >> num;
    dfs(1);
    cout << ans;
    return 0;
}
