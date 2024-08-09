#include <iostream>
#define N (1 << 17) + 1

using namespace std;

int light[N];

int main()
{
    int cur = 0;
    int num;
    int front = 0;
    int len = 0;
    long long time;
    cin >> num;
    cin >> time;
    for (int i = 0; i < num; i++)
    {
        int temp;
        cin >> temp;
        cur |= temp << i;
    }
    light[0] = cur;
    for (int tmp = 1;; tmp++)
    {
        int las = light[tmp - 1];
        int temp = las;
        for (int j = 0; j < num; j++)
        {
            int last = j - 1;
            if (last < 0)
            {
                last = num - 1;
            }
            if ((las & (1 << last)) != 0)
            {
                if ((las & (1 << j)) != 0)
                {
                    temp -= 1 << j;
                } else
                {
                    temp |= 1 << j;
                }
            }
        }
        light[tmp] = temp;
        for (int i = 0; i < tmp; i++)
        {
            if (light[i] == light[tmp])
            {
                front = i;
                len = tmp - i;
                goto end;
            }
        }
        // cout << light[tmp] << endl;
        continue;
end:
        break;
    }
    int tm1 = (time - front) % len;
    int out = light[tm1 + front];
    for (int i = 0; i < num; i++)
    {
        if ((out & (1 << i)) != 0)
        {
            cout << "1\n";
        } else
        {
            cout << "0\n";
        }
    }
    return 0;
}
