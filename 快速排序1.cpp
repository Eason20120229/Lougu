/* 快速排序 */
#include <iostream>
using namespace std;
#define ll long long 
// 将[start,end]区间进行一次划分，找到中点位置
ll partition(ll a[], ll start, ll end) {
	// 选取 start 位置的元素作为中点 pivot，以此为依据将数组划分为两部分
	swap(a[start],a[((start + end) / 2)]);
	ll pivot=a[start];
	ll i=start+1; // i 下标
	ll j=end; // j 下标
	while(i<=j) {
		while(i<=j&&a[i]<=pivot) i++; // i 下标往右移动，直到 a[i]>pivot
		while(i<=j&&a[j]>pivot) j--; // j 下标往左移动，直到 a[j]<=pivot
		if(i<j) {
			// 交换 a[i]和 a[j]的值
			swap(a[i],a[j]);
			// i 和 j 往中间靠拢
			i++;
			j--;
		}
	}
	// 交换 pivot 和 a[j]
	// 注意不要写 swap(pivot,a[j])
	swap(a[start],a[j]);
	return j; // 返回中间位置
}
// 将数组的[start,end]区间进行排序
void f(ll array[], ll start, ll end) {
	// 递归出口
	if(start>=end) {
		return;
	}
	// 将[start,end]区间进行一次划分，找到中点位置
	ll mid=partition(array, start, end);
	// 递归处理左半区域[start,mid-1]
	f(array, start, mid-1);
	// 递归处理右半区域[mid+1,end]
	f(array, mid+1, end);
}
void quickSort(ll array[], ll n) {
	// 将数组的[1,n]区间进行排序，即可排序整个数组
	f(array, 1, n);
}
int main() {
	freopen("P1177_3.in","r",stdin);
	freopen("P1177_3.out","w",stdout);
	// 1、输入数据
	ll n;
	cin>>n;
	ll a[n+1]= {};
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	// 2、快速排序
	quickSort(a,n);
	// 3、输出结果
	for(ll i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

