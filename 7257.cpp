#include <iostream>
#include <string>

using namespace std;

int main()
{
    string one;
    string two;
    cin >> one >> two;
    for (int i = 0; i < one.size() / 2; i++)
    {
        swap(one[i], one[one.size() - i - 1]);
    }
    for (int i = 0; i < two.size() / 2; i++)
    {
        swap(two[i], two[two.size() - i - 1]);
    }
    if (one.size() > two.size() || (one.size() == two.size() && one > two))
    {
        cout << one;
    }
    if (one.size() < two.size() || (one.size() == two.size() && one < two))
    {
        cout << two;
    }
    return 0;
}
