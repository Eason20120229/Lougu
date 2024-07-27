#include <iostream>

using namespace std;

int main(){
	string a,b;
	string c;
	cin >> a >> b;
	for(int i = 0;i < a.size();i++){
		if(a[i] == b[i]) c += '0';
		else c += '1';
	}
	int ans = 0;
	int s = -1;
	for(int i = 0;i < c.size();i++){
		if(c[i] == '1'){
			if(s == -1){
				s = i;
			}else{
				ans += i - s;
				s = -1;
			}
		}
	}
	cout << ans;
	return 0;
}
