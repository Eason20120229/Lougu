#include <iostream>
#include <string>
#define BASE 10
#define N    11

using std::cout, std::cin, std::string;

bool isNum(char chr)
{
    return chr >= '0' && chr <= '9';
}

int getid(char chr)
{
    switch (chr)
    {
    case 'a': return 1;
    case 'b': return 2;
    case 'c': return 3;
    }
    return 0;
}

int num[N];

int main()
{
    int left;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        left = getid(str[i]);
        i += 3;
        if (isNum(str[i]))
        {
            num[left] = str[i] - '0';
            i++;
        } else
        {
            num[left] = num[getid(str[i])];
            i++;
        }
    }
    cout << num[1] << " " << num[2] << " " << num[3];
    return 0;
}
