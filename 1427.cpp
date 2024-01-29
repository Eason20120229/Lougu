#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main(){
	int t;
	while(1){
		cin >> t;
		if(t == 0) break;
		s.push(t);
	} 
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}


