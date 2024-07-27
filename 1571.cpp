#include <algorithm>
#include <cstdio>
#define N 100001
#define M N

int ncnt;
int mcnt;
int narr[N];
int marr[M];

bool seach(int tmp)
{
    int left = 1;
    int right = mcnt + 1;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (marr[mid] >= tmp)
        {
            right = mid;
        } else
        {
            left = mid + 1;
        }
    }
    return marr[right] == tmp;
}

int main()
{
    scanf("%d %d", &ncnt, &mcnt);
    for (int i = 1; i <= ncnt; i++)
    {
        scanf("%d", &narr[i]);
    }
    for (int i = 1; i <= mcnt; i++)
    {
        scanf("%d", &marr[i]);
    }
    std::sort(marr + 1, marr + 1 + mcnt);
    for (int i = 1; i <= ncnt; i++)
    {
        if (seach(narr[i]))
        {
            printf("%d", narr[i]);
        }
    }
    return 0;
}
