#include <iostream>
#define N 60

using namespace std;

int main()
{
    int sdh;
    int sdm;
    int edh;
    int edm;
    cin >> sdh >> sdm >> edh >> edm;
    if (edm < sdm)
    {
        edh--;
        edm += N;
    }
    cout << edh - sdh << " " << edm - sdm;
    return 0;
}
