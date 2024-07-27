#include <iostream>
#include <string>

using namespace std;

int p[4];

void print(string s,int k,int q){
    char m;
    if(p[3] == 1)
        for(char i = s[k - 1] + 1;i < s[k + 1];i++){
            m = i;
            if(q == 3){
                m = '*';
            }else if(q == 2){
                if(i >= 'a' && i <= 'z')
                    m = i - ('a' - 'A');
            }else{
                if(i >= 'A' && i <= 'Z')
                    m = i + ('a' - 'A');
            }
            for(int j = 0;j < p[2];j++)
                cout << m;
        }
    else
        for(char i = s[k + 1] - 1;i > s[k - 1];i--){
            m = i;
            if(q == 3){
                m = '*';
            }else if(q == 2){
                if(i >= 'a' && i <= 'z')
                    m = i - ('a' - 'A');
            }else{
                if(i >= 'A' && i <= 'Z')
                    m = i + ('a' - 'A');
            }
            for(int j = 0;j < p[2];j++)
                cout << m;
        }
}

int main(){
    string s = "";
    cin >> p[1] >> p[2] >> p[3];
    cin >> s;
    s = '|' + s;
    for(int k = 1;k <= s.size() - 1;k++){
        if(s[k] == '-' && s[k - 1] < s[k + 1]){
            if('0' <= s[k - 1] &&
            s[k - 1] <= '9' &&
            '0' <= s[k + 1] && s[k + 1] <= '9'){
                if(p[1] == 3) print(s,k,3);
                else print(s,k,1);
                continue;
            }
            if(('a' <= s[k - 1] &&
                        s[k - 1] <= 'z' &&
                        'a' <= s[k + 1] &&
                        s[k + 1] <= 'z') ||
            ('A' <= s[k - 1] &&
                        s[k - 1] <= 'Z' &&
                        'A' <= s[k + 1] &&
                        s[k + 1] <= 'Z')){
                print(s,k,p[1]);
                continue;
            }
        }
        cout << s[k];
    }
    return 0;
}
