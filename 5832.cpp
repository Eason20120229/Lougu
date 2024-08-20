#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    int ans = 0;
    string str;
    cin >> num >> str;
    for (int len = 0; len < num; len++)
    {
        bool suc = true;
        for (int i = 0; i + len < num; i++)
        {
            bool sucs = true;
            for (int j = i + 1; j + len < num; j++)
            {
                bool flag = true;
                for (int k = 0; k <= len; k++)
                {
                    flag &= str[i + k] == str[j + k];
                }
                if (flag)
                {
                    sucs = false;
                    break;
                }
            }
            if (!sucs)
            {
                suc = false;
                break;
            }
        }
        if (suc)
        {
            ans = len + 1;
            break;
        }
    }
    cout << ans;
    return 0;
}
