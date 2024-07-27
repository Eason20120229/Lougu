#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0;i <= sqrt(n);i++){
		if(i * i > n) break;
		if(i * i == n){
			cout << "0 0 0 " << i;
			return 0;
		}
		for(int j = i;j <= sqrt(n);j++){
			if(i * i + j * j > n) break;
			if(i * i + j * j == n){
				cout << "0 0 " << i << " " << j;
				return 0;
			}
			for(int k = j;k <= sqrt(n);k++){
				if(i * i + j * j + k * k > n) break;
				if(i * i + j * j + k * k == n){ 
					cout << "0 " << i << " " << j << " " << k;
					return 0;
				}
				if(pow(int(sqrt(n - (i * i + j * j + k * k))),2) == n - (i * i + j * j + k * k)){
					cout << i << " " << j << " " << k << " " << sqrt(n - (i * i + j * j + k * k));
					return 0;
				}
			}
		}
	}
	return 0;
}
