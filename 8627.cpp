#include <iostream>

using namespace std;

int main(){
	int n,ans = 0;
	cin >> n;
	ans = n;
	while(n >= 3){
		ans += n / 3;
		n = n / 3 + n % 3;
	}
	cout << ans;
	return 0;
}
