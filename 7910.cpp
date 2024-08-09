#include <algorithm>
#include <iostream>
#define N 8001

using std::cin, std::cout, std::endl, std::copy, std::sort;

struct myint
{
    int value;
    int id;
} arr[N], tmp[N];

int rank[N];

bool cmp(myint a, myint b)
{
    if (a.value == b.value)
    {
        return a.id < b.id;
    }
    return a.value < b.value;
}

auto main() -> int
{
    int num;
    int qcnt;
    cin >> num >> qcnt;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i].value;
        arr[i].id = i;
    }
    copy(arr + 1, arr + num + 1, tmp + 1);
    sort(tmp + 1, tmp + 1 + num, cmp);
    for (int i = 1; i <= num; i++)
    {
        rank[tmp[i].id] = i;
    }
    while (qcnt-- != 0)
    {
        int kind;
        cin >> kind;
        if (kind == 1)
        {
            int idt;
            int ttt;
            int value;
            int cnt = 0;
            cin >> idt >> value;
            ttt = rank[idt];
            for (int i = 1; i < idt; i++)
            {
                if (arr[i].value == value)
                {
                    cnt++;
                }
            }
            arr[idt].value = value;
            for (int i = ttt; i < num; i++)
            {
                std::swap(tmp[i], tmp[i + 1]);
            }
            tmp[num].value = value;
            int jint = num;
            while (tmp[jint - 1].value >= tmp[jint].value)
            {
                std::swap(tmp[jint], tmp[jint - 1]);
                jint--;
            }
            for (int i = jint; i < jint + cnt; i++)
            {
                std::swap(tmp[i], tmp[i + 1]);
            }
            for (int i = 1; i <= num; i++)
            {
                rank[tmp[i].id] = i;
            }
        } else
        {
            int idt;
            cin >> idt;
            cout << rank[idt] << endl;
        }
    }
    return 0;
}
