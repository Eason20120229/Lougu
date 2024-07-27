#include <iostream>
#include <string>

int main()
{
    std::string playerName;
    int playerAge;

    std::cout << "欢迎来到冒险岛！" << std::endl;
    std::cout << "请输入你的名字：";
    std::cin >> playerName;
    std::cout << "你好, " << playerName << "。请输入你的年龄：";
    std::cin >> playerAge;

    std::cout << std::endl;
    std::cout << "你站在一个神秘的森林入口。你听到了远处传来的咆哮声。"
              << std::endl;
    std::cout << "你想要向左走还是向右走？(left/right): ";

    std::string choice;
    std::cin >> choice;

    if (choice == "left")
    {
        std::cout << "你沿着小径走着，突然一只巨大的狼出现在你面前！"
                  << std::endl;
        if (playerAge < 18)
        {
            std::cout
                << "但是由于你年纪太小，狼将你当作了玩伴，于是你获得了一个新的朋友！"
                << std::endl;
        } else
        {
            std::cout << "你勇敢地面对狼，并成功驱赶了它！" << std::endl;
        }
    } else if (choice == "right")
    {
        std::cout << "你走进了一个神秘的洞穴，发现里面有一堆宝藏！"
                  << std::endl;
        if (playerAge < 18)
        {
            std::cout << "但是年纪太小，你无法携带这些宝藏，所以你离开了洞穴。"
                      << std::endl;
        } else
        {
            std::cout << "你成功携带了这些宝藏，成为了传说中的富翁！"
                      << std::endl;
        }
    } else
    {
        std::cout << "无效的选择，你迷失在森林中..." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "游戏结束，谢谢你参与冒险岛之旅！" << std::endl;

    return 0;
}
