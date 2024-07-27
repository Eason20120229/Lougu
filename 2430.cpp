#include <iostream>
#define N 101
#define M 5001

int arr[N];
int typ[N];
int score[N];
int dparr[N][M];

int main()
{
    int wang;
    int wky;
    int num;
    int cnt;
    int time;
    std::cin >> wky >> wang >> num >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        std::cin >> arr[i];
        arr[i] *= wang / wky;
    }
    for (int i = 1; i <= num; i++)
    {
        std::cin >> typ[i] >> score[i];
    }
    std::cin >> time;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= time; j++)
        {
            dparr[i][j] = dparr[i - 1][j];
            if (j >= arr[typ[i]])
            {
                dparr[i][j] = std::max(
                    dparr[i][j], dparr[i - 1][j - arr[typ[i]]] + score[i]);
            }
        }
    }
    std::cout << dparr[num][time];
    return 0;
}
