#include <bits/stdc++.h>

using namespace std;

struct apple{
	int x,y;
}apples[5001];

bool cmp(apple a,apple b){
	return a.y < b.y;
}

int n,s,a,b,m;
int ans;

int main(){
	cin >> n >> s >> a >> b;
	for(int i = 0;i < n;i++){
		cin >> apples[i].x >> apples[i].y;
	}
	m = a + b;
	sort(apples,apples + n,cmp);
	for(int i = 0;i < n;i++){
		if(apples[i].x <= m && s >= apples[i].y){
			ans++;
			s -= apples[i].y;
		}
		else if(s < apples[i].y) break;
	}
	cout << ans;
}
