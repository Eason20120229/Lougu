/* �������� */
#include <iostream>
using namespace std;
#define ll long long 
// ��[start,end]�������һ�λ��֣��ҵ��е�λ��
ll partition(ll a[], ll start, ll end) {
	// ѡȡ start λ�õ�Ԫ����Ϊ�е� pivot���Դ�Ϊ���ݽ����黮��Ϊ������
	swap(a[start],a[((start + end) / 2)]);
	ll pivot=a[start];
	ll i=start+1; // i �±�
	ll j=end; // j �±�
	while(i<=j) {
		while(i<=j&&a[i]<=pivot) i++; // i �±������ƶ���ֱ�� a[i]>pivot
		while(i<=j&&a[j]>pivot) j--; // j �±������ƶ���ֱ�� a[j]<=pivot
		if(i<j) {
			// ���� a[i]�� a[j]��ֵ
			swap(a[i],a[j]);
			// i �� j ���м俿£
			i++;
			j--;
		}
	}
	// ���� pivot �� a[j]
	// ע�ⲻҪд swap(pivot,a[j])
	swap(a[start],a[j]);
	return j; // �����м�λ��
}
// �������[start,end]�����������
void f(ll array[], ll start, ll end) {
	// �ݹ����
	if(start>=end) {
		return;
	}
	// ��[start,end]�������һ�λ��֣��ҵ��е�λ��
	ll mid=partition(array, start, end);
	// �ݹ鴦���������[start,mid-1]
	f(array, start, mid-1);
	// �ݹ鴦���Ұ�����[mid+1,end]
	f(array, mid+1, end);
}
void quickSort(ll array[], ll n) {
	// �������[1,n]����������򣬼���������������
	f(array, 1, n);
}
int main() {
	freopen("P1177_3.in","r",stdin);
	freopen("P1177_3.out","w",stdout);
	// 1����������
	ll n;
	cin>>n;
	ll a[n+1]= {};
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	// 2����������
	quickSort(a,n);
	// 3��������
	for(ll i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

