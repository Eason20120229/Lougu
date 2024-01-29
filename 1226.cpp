#include <bits/stdc++.h>

using namespace std;

int main(){
	//freopen("P1226_6.in","r",stdin);
	//freopen("P1226_6.out","w",stdout);
	long long a,b,p,ans = 1,t,t2;
	cin >> a >> b >> p;
	t = b;
	t2 = a;
	while(t){
		if(t & 1){
			ans *= t2;
			ans %= p;
		}
		t2 *= t2;
		t2 %= p;
		t /= 2;
	}
	cout << a << "^" << b << " mod " << p << "=" << ans;
	return 0;
}

