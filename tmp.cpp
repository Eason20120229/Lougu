#include <iostream>
#include <string>

using namespace std;

struct
{
    string str;
    int cur;
} input;

int ans0;
int ans1;
int map[301];

int round(int score);

int eval(int p,int score)
{
    int left;
    if(input.str[input.cur] == '(')
    {
        left = round(score);
    }else if(input.str[input.cur] <= '9' && input.str[input.cur] >= '0')
    {
        left = input.str[input.cur] - '0';
    }
    input.cur++;
    for(;input.cur < input.str.size();input.cur++)
    {
        cout << left << "/" << input.cur << "/" << input.str[input.cur] << "/" << map[input.str[input.cur]] << endl;
        if(map[input.str[input.cur]] > p)
        {
            if(input.str[input.cur] == '|')
            {
                if(p == -1) cout << "33333\n";
                if(left == 1)
                {
                    ans0 += score;
                    input.cur++;
                    eval(map[input.str[input.cur]],0);
                    left = 1;
                }else
                {
                    input.cur++;
                    left = left | eval(map[input.str[input.cur]],score);
                }
                if(p == -1) cout << "33333\n";
            }else if(input.str[input.cur] == '&')
            {
                if(p == -1) cout << "33333\n";
                if(left == 0)
                {
                    ans1 += score;
                    input.cur++;
                    eval(map[input.str[input.cur]],0);
                    left = 0;
                }else
                {
                    input.cur++;
                    left = left & eval(map[input.str[input.cur]],score);
                }
                if(p == -1) cout << "33333\n";
            }
        }
        else
        {
            input.cur--;
            cout << "break" << endl;
            break;
        }
    }
    return left;
}

int round(int score)
{
    input.cur++;
    cout << input.cur << "------\n";
    int tmp = eval(0,score);
    input.cur++;
    cout << input.cur << "------\n";
    return tmp;
}

int main()
{
    cin >> input.str;
    input.cur = 0;
    map[')'] = -4;
    map['('] = 4;
    map['&'] = 3;
    map['|'] = 2;
    cout << eval(-1,1) << endl;
    cout << ans0 << " " << ans1;
    return 0;
}
