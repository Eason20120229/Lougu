#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl, std::vector, std::string;

vector< int > get_next(const string &patt)
{
    vector< int > next{0};
    int ps_len = 0;
    int iint = 1;
    while (iint < patt.size())
    {
        if (patt[ps_len] == patt[iint])
        {
            ps_len++;
            next.push_back(ps_len);
            iint++;
        } else
        {
            if (ps_len == 0)
            {
                next.push_back(ps_len);
                iint++;
            } else
            {
                ps_len = next[ps_len - 1];
            }
        }
    }
    return next;
}

vector< int > kmp(const string &str, const string &patt)
{
    vector< int > next = get_next(patt);
    vector< int > ans;
    int iint = 0;
    int jint = 0;
    while (iint < str.size())
    {
        if (str[iint] == patt[jint])
        {
            iint++;
            jint++;
        } else if (jint > 0)
        {
            jint = next[jint - 1];
        } else
        {
            iint++;
        }
        if (jint == patt.size())
        {
            ans.push_back(iint - jint);
        }
    }
    return ans;
}

int main()
{
    string str;
    string patt;
    cin >> str >> patt;
    vector< int > ans = kmp(str, patt);
    vector< int > next = get_next(patt);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << endl;
    }
    for (int i = 0; i < next.size(); i++)
    {
        cout << next[i] << " ";
    }
    return 0;
}
