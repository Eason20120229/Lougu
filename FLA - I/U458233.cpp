#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int m;
    string a;
    string b;
    char chr = 'a';
    cin >> n >> m >> a >> b;
    int sumb = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '#')
        {
            sumb++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '#')
        {
            if (chr != 'a')
            {
                if (sumb >= 'z' - chr + 1)
                {
                    sumb -= ('z' - chr + 1);
                    chr = 'a';
                }
            }
            a[i] = chr;
            chr++;
            if (chr > 'z')
            {
                chr = 'a';
            }
        }
    }
    cout << a;
    return 0;
}
