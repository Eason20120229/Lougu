#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n;
	cin >> n;
	while(n != 1){
		ll t;
		if(n % 2 == 1){
			t = n * 3 + 1;
			cout << n << "*3+1=" << t << endl;
		}else{
			t = n / 2;
			cout << n << "/2=" << t << endl;
		}
		n = t;
	} 
	cout << "End";
	return 0;
}


