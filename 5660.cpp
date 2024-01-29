#include <bits/stdc++.h>

using namespace std;

int main(){
	int ans = 0;
	string s;
	cin >> s;
	for(int i = 0;i < 8;i++){
		if(s[i] == '1'){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
