#include <bits/stdc++.h>
using namespace std;

stack<char> s;

int main(){
	int i = 0;
	string str;
	cin >> str;
	while(str[i] != '@'){
		if(str[i] == '('){
			s.push('(');
		}
		if(str[i] == ')'){
			if(!s.empty() && s.top() == '('){
				s.pop();
			}else{
				s.push(')');
				break;
			}
		}
		i++;
	}
	if(s.empty()){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}


