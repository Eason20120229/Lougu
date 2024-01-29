/*

错误1
    没有处理x > y时的复杂度(两次)
错误2
    复杂度读取时只处理一位
错误3
    没有处理同级循环
错误4
    当s空时，输入E会越界
错误5
    x,y比较时,没有化成整数
    (解决方法是先比较x,y的长度)

(以上改正完成)

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> s; //栈
vector<string> a; 
int cnt = 0; //记录复杂度

bool cmp(string x,string y){ //比较
    if(x.size() > y.size()) return true; //比较x,y的长度
    else if(x.size() < y.size()) return false;
    else return x > y; //长度相等
}

void back(){ //重置
    s.erase(s.begin(),s.end());
    a.erase(a.begin(),a.end());
    cnt = 0;
}

int input(){ //输入并处理
    char c; //F或E
    cin >> c;
    if(c == 'E'){
        if(s.empty()){ //避免越界并判断是否F
            cout << "ERR" << endl;
            return 0;
        }else{
            int cntt = 0;
            for(int i = 0;i < s.size();i++){ // 计算复杂度
                if(s[i] == 2) break;
                cntt += s[i];
            }
            cnt = max(cnt,cntt); //更新答案
            a.erase(a.end() - 1,a.end()); //去除局部变量
            s.erase(s.end() - 1,s.end()); //去除一对FE
        }
    }else{
        string i,x,y;
        cin >> i >> x >> y;
        int g = a.size();
        for(int k = 0;k < g;k++){ //检测是否定义过
            if(a[k] == i){
                cout << "ERR" << endl;
                return 0;
            }
        }
        a.push_back(i); //定义
        if(x != y && y == "n") s.push_back(1); //循环n遍
        else if(x != y && x == "n" || cmp(x,y)) //不循环
            s.push_back(2);
        else s.push_back(0); //循环1遍
    }
    return 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string n;
        int f,t = 0;
        cin >> f >> n;
        int b = 0;
        while(f){ //输入并处理数据
            int h = input();
            if(!h){ //出错就退出
                b = 1;
                break;
            }
            f--;
        }
        string g;
        while(f){ //读入剩余数据
            getline(cin,g);
            g = "";
            f--;
        }
        if(b){
            back();
            continue;
        }
        if(!s.empty()){ //剩余未匹配
            cout << "ERR" << endl;
            back();
            continue;
        }
        int i = n.size() - 2; //字符串转数字
        int shi = 1;
        int sum = 0;
        int j = 4;
        while(i >= j){
            sum += shi * (n[i] - '0');
            shi *= 10;
            i--;
        }
        if(n == "O(1)" && cnt == 0) t = 1; 
        else if(n != "O(1)" && sum == cnt) t = 1;
        if(t) cout << "Yes" << endl;
        else cout << "No" << endl;
        cnt = 0;
        back();
    }
    return 0;
}