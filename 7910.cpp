#include <iostream>
#include <cstring>

using namespace std;

int a[8001],b[8001],c[8001],d[8001];
int n,Q;

void sort(){
	memset(b,0,sizeof(b));
	for(int i = 1;i <= n;i++){
		b[i] = c[i];
	}
	memset(d,0,sizeof(b));
	for(int i = 1;i <= n;i++){
		d[i] = a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j >= 2;j--){
			if(b[j] < b[j - 1]){
				swap(b[j],b[j - 1]);
				swap(d[j],d[j - 1]);
			}
		}
	}
}

int main(){
	
	cin >> n >> Q;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	memset(c,0,sizeof(b));
	for(int i = 1;i <= n;i++){
		c[i] = a[i];
	}
	while(Q--){
		int type;
		cin >> type;
		if(type == 1){
			int x,v;
			cin >> x >> v;
			c[x] = v;
		}else{
			int x;
			cin >> x;
			sort();
			for(int i = 1;i <= n;i++){
				if(d[i] == a[x]){
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}
