#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int w,m,n;
	cin >> w >> m >> n;
	if(m > n) swap(m,n);
	int tm = (m / w % 2 == 0 ? m % w : w - m % w + 1);
	int tn = (n / w % 2 == 0 ? n % w : w - n % w + 1);
	int ans = (n / w - m / w) + abs(tm - tn);
	cout << ans;
	return 0;
}
