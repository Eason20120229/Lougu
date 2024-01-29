#include <iostream>

using namespace std;

int main(){
	int a,m = 0,b = 0;
	for(int i = 0;i < 12;i++){
		cin >> a;
		m = m + 300 - a;
		if(m < 0) {
			cout << "-" << (i + 1);
			return 0;
		}
		b += m / 100;
		m = m % 100;
	}
	cout << (m + b * 120);
	return 0;
}
