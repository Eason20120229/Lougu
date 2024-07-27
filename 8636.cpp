#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[100],b[100];

bool cmp(int a,int b){
	return a > b;
}

int main(){
	int n;
	cin >> n;
	int s[100] = {};
	for(int i = 0;i < n;i++){
		cin >> s[i];
	}
	sort(s,s + n,cmp);
	int m = 0;
	for(int i = 0;i < n - 1;i++){
		a[i] = s[i];
		b[i] = s[i + 1];
		int t = __gcd(a[i],b[i]);
		a[i] /= t;
		b[i] /= t;
		cout << a[i] << " " << b[i] << " " << t << endl;
		m = max(a[i],m);
		m = max(b[i],m);
	}
	int visita[m][100] = {};
	int visitb[m][100] = {};
	int maxa = 0,minb = 0x7fffffff;
	for(int i = 1;i <= m;i++){
		int k = 1;
		for(;k <= m;){
			k *= i;
			for(int o = 0;o < n - 1;o++){
				if(k == a[o]) visita[i][o] = k;
				if(k == b[o]) visitb[i][o] = k;
			}
			if(k == 1) break;
		}
	}
	cout << maxa << "/" << minb;
	return 0;
}