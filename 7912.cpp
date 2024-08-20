#include <iostream>
#include <list>

struct node
{
    int num;
    int type;
    std::list< int > id;
};

std::list< node > lis;

auto main() -> int
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (lis.empty() || lis.back().type != tmp)
        {
            lis.push_back({1, tmp});
            lis.back().id.push_back(i);
        } else
        {
            lis.back().num++;
            lis.back().id.push_back(i);
        }
    }
    while (!lis.empty())
    {
        for (auto &lit : lis)
        {
            printf("%d ", lit.id.front());
            lit.id.pop_front();
            lit.num--;
        }
        for (auto i = lis.begin(); i != lis.end();)
        {
            auto tmp = ++i;
            auto tmp2 = --(--i);
            ++i;
            if (i->num == 0)
            {
                bool flag = i != lis.begin();
                lis.erase(i);
                if (flag && tmp != lis.end() && tmp->type == tmp2->type)
                {
                    tmp2->num += tmp->num;
                    tmp2->id.splice(tmp2->id.end(), tmp->id);
                    lis.erase(tmp);
                }
                i = ++tmp2;
            } else
            {
                i = tmp;
            }
        }
        // std::cout << "-" << lis.size();
        printf("\n");
    }
    return 0;
}
