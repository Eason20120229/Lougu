/*

����1
    û�д���x > yʱ�ĸ��Ӷ�(����)
����2
    ���Ӷȶ�ȡʱֻ����һλ
����3
    û�д���ͬ��ѭ��
����4
    ��s��ʱ������E��Խ��
����5
    x,y�Ƚ�ʱ,û�л�������
    (����������ȱȽ�x,y�ĳ���)

(���ϸ������)

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> s; //ջ
vector<string> a; 
int cnt = 0; //��¼���Ӷ�

bool cmp(string x,string y){ //�Ƚ�
    if(x.size() > y.size()) return true; //�Ƚ�x,y�ĳ���
    else if(x.size() < y.size()) return false;
    else return x > y; //�������
}

void back(){ //����
    s.erase(s.begin(),s.end());
    a.erase(a.begin(),a.end());
    cnt = 0;
}

int input(){ //���벢����
    char c; //F��E
    cin >> c;
    if(c == 'E'){
        if(s.empty()){ //����Խ�粢�ж��Ƿ�F
            cout << "ERR" << endl;
            return 0;
        }else{
            int cntt = 0;
            for(int i = 0;i < s.size();i++){ // ���㸴�Ӷ�
                if(s[i] == 2) break;
                cntt += s[i];
            }
            cnt = max(cnt,cntt); //���´�
            a.erase(a.end() - 1,a.end()); //ȥ���ֲ�����
            s.erase(s.end() - 1,s.end()); //ȥ��һ��FE
        }
    }else{
        string i,x,y;
        cin >> i >> x >> y;
        int g = a.size();
        for(int k = 0;k < g;k++){ //����Ƿ����
            if(a[k] == i){
                cout << "ERR" << endl;
                return 0;
            }
        }
        a.push_back(i); //����
        if(x != y && y == "n") s.push_back(1); //ѭ��n��
        else if(x != y && x == "n" || cmp(x,y)) //��ѭ��
            s.push_back(2);
        else s.push_back(0); //ѭ��1��
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
        while(f){ //���벢��������
            int h = input();
            if(!h){ //������˳�
                b = 1;
                break;
            }
            f--;
        }
        string g;
        while(f){ //����ʣ������
            getline(cin,g);
            g = "";
            f--;
        }
        if(b){
            back();
            continue;
        }
        if(!s.empty()){ //ʣ��δƥ��
            cout << "ERR" << endl;
            back();
            continue;
        }
        int i = n.size() - 2; //�ַ���ת����
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