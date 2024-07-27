#include<bits/stdc++.h>
using namespace std;
int n,a[10010],m;
int g;

bool dfs(int x){
	//x达到序列长度
	if(x == m){
		//a数组的第m个，也就是第x个必须是n
		if(a[m] == n){
			//输出
			for(int i = 0;i < m;i++)
				cout << a[i] << " ";
			cout << a[m] << endl;
			return true;
		}
		//不满足
		return false;
	}
	//计算能达到最大n
	g = 2;
	int ans = 1;
	int t = m - x;
	while(t){
		if(t & 1){
			ans *= g;
		}
		t /= 2;
		g *= g;
	}
	if(ans * a[x] < n) return false;
	//下一个数a[x + 1]相当于k
	if(n - a[x] < m - x) return false;
	for(int i = 0;i <= x;i++){
		a[x + 1] = a[i] + a[x]; //计算a[x + 1]
		if(a[x + 1] <= a[x]) continue; //值不大于前一个
		if(a[x + 1] > n ||
			(a[x + 1] == n && x + 1 != m)){ //值不小于n
			break;
		}
		//判断a[x + 1] = a[i] + a[j]是否能成立
		if(dfs(x + 1))
			return true;
	}
	//没有找到
	return false;
}
int main(){
	cin >> n;
	while(n){
		a[0] = 1; //下标为0的数为1
		//n = 1时,可以让m = 0,由于k >= 1,所以不判断k,符合条件
		if(n == 1) cout << 1 << endl;
		for(m = 1;m < n;m++) //枚举数列长度
			if(dfs(0)) //判断是否符合
				break;
		cin >> n;
	}
	return 0;
} 
