#include<bits/stdc++.h>
using namespace std;

int b[5][2] = {1,9,2,8,3,7,4,6,5,0};

int main(){
    int a[5] = {1,1,1,1,1};
    string s;
    cin >> s;
    if(s[0] == 'M' && s[1] == 'D' && s[2] == 'A'){
        int t = -1;
        for(int i = 3;i < 8;i++){
            if(s[i] >= '0' && s[i] <= '9'){
                t = (s[i] - '0');
            }
        }
        for(int i = 0;i < 5;i++){
            if(!(t == b[i][0] || t == b[i][1])){
                a[i] = 0;
            }
        }
    }
    for(int i = 0;i < 5;i++){
        cout << a[i] << " ";
    }
    return 0;
}