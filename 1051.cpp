#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int score;
    int in_class;
    char is_manager;
    char is_east;
    int text;
} tmp;

int main()
{
    int num;
    std::string name;
    int maxscore = -1;
    int ans = 0;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int tmpscore = 0;
        std::cin >> tmp.name >> tmp.score >> tmp.in_class >> tmp.is_manager >>
            tmp.is_east >> tmp.text;
        // 计算得分
        if (tmp.score > 80 && tmp.text >= 1)
        {
            tmpscore += 8000;
        }
        if (tmp.score > 85 && tmp.in_class > 80)
        {
            tmpscore += 4000;
        }
        if (tmp.score > 90)
        {
            tmpscore += 2000;
        }
        if (tmp.score > 85 && tmp.is_east == 'Y')
        {
            tmpscore += 1000;
        }
        if (tmp.in_class > 80 && tmp.is_manager == 'Y')
        {
            tmpscore += 850;
        }
        if (tmpscore > maxscore)
        {
            maxscore = tmpscore;
            name = tmp.name;
        }
        ans += tmpscore;
    }
    std::cout << name << "\n" << maxscore << "\n" << ans << "\n";
    return 0;
}
