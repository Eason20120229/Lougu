#include <iostream>
#include <list>

std::list< int > lis;

void check(std::list< int >::iterator &iint)
{
    if (iint == lis.end())
    {
        iint = lis.begin();
    }
}

void inadd(std::list< int >::iterator &iint, int num)
{
    for (int j = 0; j < num; j++)
    {
        iint++;
        check(iint);
    }
}

int main()
{
    int num;
    int cnt;
    std::cin >> num >> cnt;
    for (int i = 1; i <= num; i++)
    {
        lis.push_back(i);
    }
    auto i = lis.begin();
    inadd(i, cnt - 1);
    for (; !lis.empty();)
    {
        std::cout << *i << " ";
        auto tmp = ++i;
        i--;
        lis.erase(i);
        i = tmp;
        check(i);
        inadd(i, cnt - 1);
    }
    return 0;
}
