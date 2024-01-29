#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k;

int main(){
	cin >> k;
	while(k--){
		ll n,d,e;
		ll p = 0,q = 0,t = 0,f = 0;
		cin >> n >> d >> e;
		t = d * e;
		for(int i = 1;i < sqrt(n);i++){
			if(n % i == 0 && (i - 1) * (n / i - 1) + 1 == t){
				p = i;
				q = n / i;
				f = 1;
				break;
			}
		}
		if(f){
			if(p > q) swap(p,q);
			cout << p << " " << q << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
