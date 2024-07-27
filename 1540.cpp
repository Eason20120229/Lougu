#include <cstdio>
#define N 2001

int my_que[N];
int front = 0;
int back = -1;
int ans;

int main()
{
    int cap;
    int num;
    scanf("%d %d", &cap, &num);
    for (int i = 1; i <= num; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        for (int i = front; i <= back; i++)
        {
            if (my_que[i] == tmp)
            {
                goto end;
            }
        }
        my_que[++back] = tmp;
        ans++;
        if (back - front + 1 > cap)
        {
            front++;
        }
end:
        continue;
    }
    printf("%d", ans);
    return 0;
}
