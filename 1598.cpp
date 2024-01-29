#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
	int a[26] = {};
	string s;
	int m = 0;
	for(int i = 0;i < 4;i++){
		getline(cin,s);
		for(int j = 0;j < s.length();j++){
			if(s[j] <= 'Z' && s[j] >= 'A') a[s[j] - 'A']++;
		}
	}
	for(int i = 0;i < 26;i++){
		m = max(m,a[i]);
	}
	for(int i = m;i >= 1;i--){
		if(a[0] == i){
			a[0]--;
			cout << "*";
		}else{
			cout << " ";
		}
		int t = 0;
		for(int j = 25;j >= 1;j--){
			if(a[j] == i){
				t = j;
				break;
			}
		}
		//cout << t << endl;
		for(int j = 1;j <= t;j++){
			if(a[j] == i){
				a[j]--;
				cout << " " << "*";
			}else{
				cout << "  ";
			}
		}
		cout << endl;
	}
	cout << 'A';
	for(int i = 1;i < 26;i++){
		cout << " " << char('A' + i);
	}
	return 0;
}


