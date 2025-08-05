#include <cstring>
#include <iostream>
#define LEN 6
#define M   47

using namespace std;

int getn(const char *str)
{
    int ans = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        ans *= str[i] - 'A' + 1;
        ans %= M;
    }
    return ans;
}

int main()
{
    char group[LEN + 1];
    char ufo[LEN + 1];
    int gnum;
    int unum;
    cin >> group >> ufo;
    gnum = getn(group);
    unum = getn(ufo);
    if (gnum == unum)
    {
        cout << "GO";
    } else
    {
        cout << "STAY";
    }
    return 0;
}
