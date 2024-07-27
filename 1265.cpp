#include <cmath>
#include <iostream>
#include <iomanip>
#define N 5001

struct point
{
    double x;
    double y;
};

point city[N];
double minn[N];

double third(point one, point two)
{
    return sqrt(pow(one.x - two.x, 2) + pow(one.y - two.y, 2));
}

int main()
{
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> city[i].x >> city[i].y;
    }
    int start = 1;
    double ans = 0;
    minn[start] = 0x7fffffff;
    for (int i = 2; i <= num; i++)
    {
        minn[i] = third(city[start], city[i]);
    }
    for (int i = 1; i < num; i++)
    {
        double maxx = 0x7fffffff;
        int cur = 0;
        for (int j = 1; j <= num; j++)
        {
            if (minn[j] < maxx)
            {
                cur = j;
                maxx = minn[j];
            }
        }
        ans += minn[cur];
        minn[cur] = 0x7fffffff;
        for (int j = 1; j <= num; j++)
        {
            if (minn[j] != 0x7fffffff && minn[j] > third(city[cur], city[j]))
            {
                minn[j] = third(city[cur], city[j]);
            }
            // std::cout << j << " " << minn[j] << std::endl;
        }
        // std::cout << "------" << std::endl << cur << " " << ans << std::endl;
    }
    std::cout << std::fixed << std::setprecision(2) << ans;
    return 0;
}
