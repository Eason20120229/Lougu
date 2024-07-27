#include <iostream>
#include <string>
#define BASE 10

using std::cout, std::cin, std::string;

bool isNum(char chr)
{
    return chr >= '0' && chr <= '9';
}

int main()
{
    int one;
    int two;
    int three;
    int left;
    int right;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
        {
            left = 1;
            right = 0;
        }
        if (str[i] == 'b')
        {
            left = 2;
            right = 0;
        }
        if (str[i] == 'c')
        {
            left = 3;
            right = 0;
        }
        if (isNum(str[i]))
        {
            right = right * BASE + (str[i] - '0');
        }
        if (str[i] == ';')
        {
            if (left == 1)
            {
                one = right;
            }
            if (left == 2)
            {
                two = right;
            }
            if (left == 3)
            {
                three = right;
            }
        }
    }
    cout << one << " " << two << " " << three;
    return 0;
}
