/*

理解错误
    （3）组成数去0 -> 每一个数去0。

*/

#include<bits/stdc++.h>
using namespace std;

struct{
    string s;
    int a;
}c[7] = {"",0,"a",1,"both",2,"another",1,
    "first",1,"second",2,"third",3};

string a[21] = {"","one","two","three","four","five",
    "six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen",
    "sixteen","seventeen","eighteen","nineteen","twenty"};
int b[6] = {},cnt = 0;

int main(){
    string s;
    for(int i = 0;i < 6;i++){
        cin >> s;
        int t = 0;
        for(int j = 1;j <= 20;j++){
            if(s == a[j]){
                t = j;
                b[cnt++] = (t * t) % 100;
                break;
            }
        }
        for(int j = 1;j <= 6;j++){
            if(s == c[j].s){
                t = c[j].a;
                b[cnt++] = (t * t) % 100;
                break;
            }
        }
    }
    sort(b,b + cnt);
    string ans = "";
    for(int i = 0;i < cnt;i++){
        string t = "";
        int j = 0;
        while(b[i]){
            t = char(b[i] % 10 + '0') + t;
            b[i] /= 10;
            j++;
        }
        while(i != 0 && j < 2 && t != ""){
            ans += '0';
            j++;
        }
        ans += t;
    }
    cout << ans;
    if(ans == "") cout << "0";
    return 0;
}