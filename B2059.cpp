#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,t;
	cin >> n >> m;
	if(n % 2 == 0) n++;
	if(m % 2 == 0) m--;
	t = (n + m) * ((m - n) / 2 + 1) / 2;
	cout << t;
	return 0;
}


