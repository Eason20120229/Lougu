#include<bits/stdc++.h>
using namespace std;

bool cmp(string x,string y){
    if(x.size() > y.size()) return true;
    else if(x.size() < y.size()) return false;
    else return x > y;
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << (a > b) << endl;
    cout << a.compare(b) << endl;
    cout << cmp(a,b);
    return 0;
}