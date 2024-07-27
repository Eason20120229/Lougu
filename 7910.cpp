#include <cstdio>
#include <iostream>
#include <utility>
#define N 8001

struct myint
{
    int value;
    int id;
} arr[N], tmp[N], mtmp[N];

int rank[N];

void merge(int left, int mid, int right)
{
    int iint = left;
    int jint = mid + 1;
    int cur = left;
    while (iint <= mid && jint <= right)
    {
        if (tmp[iint].value <= tmp[jint].value)
        {
            mtmp[cur] = tmp[iint];
            cur++;
            iint++;
        } else
        {
            mtmp[cur] = tmp[jint];
            cur++;
            jint++;
        }
    }
    while (iint <= mid)
    {
        mtmp[cur] = tmp[iint];
        cur++;
        iint++;
    }
    while (jint <= right)
    {
        mtmp[cur] = tmp[jint];
        cur++;
        jint++;
    }
    for (int i = left; i <= right; i++)
    {
        tmp[i] = mtmp[i];
    }
}

void mergesort(int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) >> 1;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    merge(left, mid, right);
}

auto main() -> int
{
    // std::freopen("7910", "w", stdout);
    int num;
    int qcnt;
    std::cin >> num >> qcnt;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> arr[i].value;
        arr[i].id = i;
    }
    std::copy(arr + 1, arr + num + 1, tmp + 1);
    mergesort(1, num);
    for (int i = 1; i <= num; i++)
    {
        rank[tmp[i].id] = i;
    }
    while (qcnt-- != 0)
    {
        int kind;
        std::cin >> kind;
        if (kind == 1)
        {
            int idt;
            int ttt;
            int value;
            int cnt = 0;
            std::cin >> idt >> value;
            for (int i = 1; i <= num; i++)
            {
                if (tmp[i].id == idt)
                {
                    ttt = i;
                    break;
                }
            }
            for (int i = 1; i < idt; i++)
            {
                if (arr[i].value == value)
                {
                    cnt++;
                }
            }
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
            std::cin >> idt;
            std::cout << rank[idt] << std::endl;
        }
    }
    return 0;
}
