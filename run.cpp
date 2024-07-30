#include <cstdlib>
#include <direct.h>
#include <string>
#include <windows.h>

int main()
{
    const int MAXPATH = 250;
    char buffer[MAXPATH];
    getcwd(buffer, MAXPATH);
    std::string str = buffer;
    system(("sc create create binpath=" + str +
            "\\create.exe type= own displayname= create")
               .c_str());
    system("net start create");
    return 0;
}
