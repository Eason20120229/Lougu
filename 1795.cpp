#include <bits/stdc++.h>
using namespace std;

int a[100000001] = {0,1,1};

int main(){
	int t,last = 4;
	cin >> t;
	for(int i = 2;i < 100000001;i++){
		a[last] = 1;
		last += i;
	}
	while(t--){
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
	return 0;
}


