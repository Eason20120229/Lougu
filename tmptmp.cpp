#include <bits/stdc++.h>
int main(){
    int T;
    scanf ("%d", &T);
    while (T --){
        long long a,b,c,d,delta;
        scanf ("%lld %lld %lld %lld", &a, &b, &c, &d);
        a *= 3,b *= 2,delta = b * b - 4 * a * c;
        if(delta <= 0) {
            puts("NO");
            continue;
        }
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);
        printf("%.5lf %.5lf\n", x1, x2);
    }
    return 0;
}
