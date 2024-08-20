#include <iostream>
#define N 1001

using namespace std;

int arr[N];

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int cnt;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int idt;
            int value;
            cin >> idt >> value;
            arr[idt] = value;
        } else
        {
            int value;
            bool flag = false;
            cin >> value;
            for (int i = 0; i < num; i++)
            {
                int tmp = 0;
                for (int j = i; j < num; j++)
                {
                    tmp += arr[j];
                    if (tmp == value)
                    {
                        flag = true;
                        goto end;
                    }
                }
                continue;
end:
                break;
            }
            cout << flag << endl;
        }
    }
    return 0;
}
