#include <cmath>
#include <cstdlib>
#include <iostream>
#define MAX  100
#define EPS  1e-3
#define N    3
#define BASE 10

double one;
double two;
double three;
double four;

auto calc(double ans) -> double
{
    return one * ans * ans * ans + two * ans * ans + three * ans + four;
}

auto main() -> int
{
    std::cin >> one >> two >> three >> four;
    for (double i = -MAX; i <= MAX; i += EPS * BASE)
    {
        if (fabs(calc(i)) < EPS)
        {
            printf("%.2lf ", i);
        }
    }
    return 0;
}
