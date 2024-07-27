#include <iostream>
#include <string>
#define N 26

int arr[N];
int arr1[N];

int main()
{
    std::string source;
    std::string dest;
    std::string trans;
    std::cin >> dest >> source >> trans;
    for (int i = 0; i < N; i++)
    {
        arr[i] = -1;
        arr1[i] = -1;
    }
    for (int i = 0; i < dest.size(); i++)
    {
        if (arr[source[i] - 'A'] != dest[i] - 'A' && arr[source[i] - 'A'] != -1)
        {
            std::cout << "Failed";
            return 0;
        }
        arr[source[i] - 'A'] = dest[i] - 'A';
        if (arr1[dest[i] - 'A'] != source[i] - 'A' && arr1[dest[i] - 'A'] != -1)
        {
            std::cout << "Failed";
            return 0;
        }
        arr1[dest[i] - 'A'] = source[i] - 'A';
    }
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == -1)
        {
            std::cout << "Failed";
            return 0;
        }
    }
    for (int i = 0; i < trans.size(); i++)
    {
        trans[i] = static_cast< char >(arr1[trans[i] - 'A'] + 'A');
    }
    std::cout << trans;
    return 0;
}
