#include <cstdio>
#include <string>

int ans;

int read()
{
    int num = 0;
    bool flag = false;
    int chr = _getchar_nolock();  // Lougu getchar_unlocked()
    while (chr != EOF && chr != ' ')
    {
        if (chr == '-')
        {
            flag = true;
        } else
        {
            num = 10 * num + (chr - '0');
        }
        chr = _getchar_nolock();  // Lougu getchar_unlocked()
    }
    if (flag)
    {
        num *= -1;
    }
    return num;
}

int main()
{
    int num;
    num = read();
    for (int i = 1; i <= num; i++)
    {
        int tmp = read();
        ans += tmp;
    }
    puts(std::to_string(ans).c_str());
    return 0;
}
