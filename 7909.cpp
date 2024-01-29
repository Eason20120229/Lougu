#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,L,R;
	cin >> n >> L >> R;
	int h = L % n;
	if(L == R) cout << (L % n);
	else if(L + (n - h) - 1 < R) cout << ((L + (n - h) - 1) % n);
	else if(R % n == 0) cout << ((R - 1) % n);
	else cout << (R % n);
	return 0;
}
