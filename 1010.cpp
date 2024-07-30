#include <iostream>

void print(int n)
{
    int a[20];
    int i = 0;
    int cnt = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            a[cnt++] = i;
        }
        i++;
        n >>= 1;
    }
    for (int i = cnt - 1; i >= 1; i--)
    {
        if (a[i] == 1)
        {
            std::cout << "2+";
        } else if (a[i] == 0)
        {
            std::cout << "2(0)+";
        } else
        {
            std::cout << "2(";
            print(a[i]);
            std::cout << ")+";
        }
    }
    if (a[0] == 1)
    {
        std::cout << "2";
    } else if (a[0] == 0)
    {
        std::cout << "2(0)";
    } else
    {
        std::cout << "2(";
        print(a[0]);
        std::cout << ")";
    }
}

int main()
{
    int n;
    std::cin >> n;
    print(n);
    return 0;
}
