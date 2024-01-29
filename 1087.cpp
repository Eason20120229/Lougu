#include <bits/stdc++.h>

using namespace std;

struct tree{
	int l,r;
	char n;
	int sl,sr;
};


string s;
tree tr[1024];
int n;
int cnt = 0;

char t(int sl,int sr){
	int a = 0,b = 0;
	for(int i = sl;i <= sr;i++){
		if(s[i] == '0'){
			a++;
		}else{
			b++;
		}
	}
	if(a == 0) return 'I';
	if(b == 0) return 'B';
	else return 'F';
}

void build(int sl,int sr){
	if(sl < sr){
		int mid = (sl + sr) / 2;
		build(sl,mid);
		build(mid + 1,sr);
	} 
	cout << t(sl,sr);
}

int main(){
	cin >> n >> s;
	build(0,(pow(2,n) - 1));
	return 0;
}
