#include <cmath>
#include <iostream>
#include <string>
#define SHIYI   11
#define ERSHIYI 21

int main()
{
    int lcnt = 0;
    int hcnt = 0;
    std::string str;
    char tmp;
    std::cin >> tmp;
    while (tmp != 'E')
    {
        str += tmp;
        std::cin >> tmp;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'W')
        {
            hcnt++;
        } else if (str[i] == 'L')
        {
            lcnt++;
        }
        if (abs(hcnt - lcnt) >= 2 && (lcnt >= SHIYI || hcnt >= SHIYI))
        {
            std::cout << hcnt << ":" << lcnt << std::endl;
            hcnt = lcnt = 0;
        }
        // std::cout << hcnt << ":" << lcnt << std::endl;
    }
    std::cout << hcnt << ":" << lcnt << "\n";
    hcnt = lcnt = 0;
    std::cout << "\n";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'W')
        {
            hcnt++;
        } else if (str[i] == 'L')
        {
            lcnt++;
        }
        if (abs(hcnt - lcnt) >= 2 && (lcnt >= ERSHIYI || hcnt >= ERSHIYI))
        {
            std::cout << hcnt << ":" << lcnt << "\n";
            hcnt = lcnt = 0;
        }
    }
    std::cout << hcnt << ":" << lcnt << "\n";
    hcnt = lcnt = 0;
    return 0;
}
