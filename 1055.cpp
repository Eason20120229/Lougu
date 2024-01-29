#include <iostream>
#include <string>

using namespace std;

int join(string str){
	int re = 0,j = 1;
	for(int i = 0;i <= 10;i++){
		if(str[i] == '-'){
			continue;
		}
		re += int(str[i] - '0') * j;
		j++;
	}
	re = re % 11;
	return re;
}

void print(string s,char c){
	if(s[12] == c){
		cout << "Right";
	}else{
		for(int i = 0;i < 12;i++){
			cout << s[i];
		}
		cout << c;
	}
}

void out(string s){
	int re = join(s);
	if(re == 10){
		print(s,'X');
	}else{
		print(s,re + '0');
	}
}

int main(){
	string s;
	cin >> s;
	out(s);
	return 0;
}
