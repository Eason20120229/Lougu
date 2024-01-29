#include <bits/stdc++.h>
using namespace std;
int a[31] = {0,1,1};
int main(){
	int n;
	cin >> n;
	while(n--){
		int h;
		cin >> h;
		for(int i = 3;i <= h;i++){
			a[i] = a[i - 1] + a[i - 2];
		}
		cout << a[h] << endl;
	}
	return 0;
}


