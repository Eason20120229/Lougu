#include <bits/stdc++.h>
using namespace std;

string a,b;

void build(int l1,int r1,int l2,int r2){
	int m = a.find(b[r2]);
	cout << b[r2];
	if(m > l1)build();
	if(m < r1)build();
}


int main(){
	int n
	cin >> a >> b;
	n = a.length();
	build(0,n - 1,0,n - 1);
	return 0;
}


