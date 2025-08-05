#include <iostream>

using namespace std;

int ta[18], tb[18];
int sa, sb;

int main()
{
    for (int i = 0; i < 18; i++)
    {
        int tmp;
        cin >> tmp;
        sa += tmp;
        switch (tmp)
        {
        case 1: ta[0]++; break;
        case 2: ta[1]++; break;
        case 3: ta[2]++; break;
        case 4: ta[3]++; break;
        case 5: ta[4]++; break;
        case 6: ta[5]++; break;
        case 7: ta[6]++; break;
        case 8: ta[7]++; break;
        case 9: ta[8]++; break;
        case 10: ta[9]++; break;
        }
    }
    for (int i = 0; i < 18; i++)
    {
        int tmp;
        cin >> tmp;
        sb += tmp;
        switch (tmp)
        {
        case 1: tb[0]++; break;
        case 2: tb[1]++; break;
        case 3: tb[2]++; break;
        case 4: tb[3]++; break;
        case 5: tb[4]++; break;
        case 6: tb[5]++; break;
        case 7: tb[6]++; break;
        case 8: tb[7]++; break;
        case 9: tb[8]++; break;
        case 10: tb[9]++; break;
        }
    }
    if (sa > sb)
    {
        cout << "Algosia";
    } else if (sa < sb)
    {
        cout << "Bajtek";
    } else
    {
        for (int i = 9; i >= 0; i--)
        {
            if (ta[i] > tb[i])
            {
                cout << "Algosia";
                return 0;
            } else if (ta[i] < tb[i])
            {
                cout << "Bajtek";
                return 0;
            }
        }
        cout << "remis";
    }
    return 0;
}
