#include <bits/stdc++.h>
using namespace std;

/*
取反某一个操作数的值时，原表达式的值为多少
思路：
1.读入表达式，将表达式建成二叉树
2.计算出表达式的值
3.深搜，求出哪些结点的值修改后对结果有影响
*/
const int N = 1e6 + 10;
struct node
{
    int v, next;
} e[N];        // 邻接表
int head[N];   // 存储以每个点为起点的最后一条边的编号
int k;         // 建边的时候使用
int num[N];    // 存储二叉树每个结点的值
char op[N];    // 存储操作符
int m;         // 表示op数组的下标
bool book[N];  // 标记哪些点的值修改后对结果有影响
int n;
string s, tmp;    // w用来存储每个操作数的下标
stack< int > st;  // 用于计算后缀表达式

// 建边
void add(int u, int v)
{  // （m,x）（m,y）
    k++;
    e[k].v = v;
    e[k].next = head[u];
    head[u] = k;
}

// 深搜求哪些结点的值修改后对结果有影响
void dfs(int x)
{
    book[x] = true;
    if (x <= n)
        return;  // 如果是叶子结点
    if (op[x] == '!')
        dfs(e[head[x]].v);
    else
    {
        int n1 = e[head[x]].v;
        int n2 = e[e[head[x]].next].v;
        if (op[x] == '&')
        {
            if (num[n1] == 1)
                dfs(n2);
            if (num[n2] == 1)
                dfs(n1);
        } else if (op[x] == '|')
        {
            if (num[n1] == 0)
                dfs(n2);
            if (num[n2] == 0)
                dfs(n1);
        }
    }
}

int main()
{
    getline(cin, s);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
    }

    // 分析表达式，建树
    int x, y;
    m = n;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            tmp = tmp + s[i];
            // 如果连续数字结束
            if (i == s.size() - 1 || !isdigit(s[i + 1]))
            {
                // c_str()：将C++中的字符串转换成c中的字符串(char op[])
                st.push(atoi(tmp.c_str()));  // 将操作数的下标入栈
                tmp = "";
            }
        } else if (s[i] == '!')
        {  // 如果是取反操作符
            // 1、将运算符存入数组op
            // 2、取1个栈顶元素计算，并将结果入栈
            // 3、建树

            m++;
            op[m] = s[i];  // 操作符的编号是m
            // 取1个操作数
            x = st.top();      // 取栈顶元素来运算
            st.pop();          // 出栈
            num[m] = !num[x];  // 通过op[m]操作的结果存入num[m]中
            st.push(m);        // 存入结果的下标，方便查找

            // 建边
            add(m, x);

        } else if (s[i] == '&' || s[i] == '|')
        {  // 如果是& |操作符
            // 1、将运算符存入数组op
            // 2、取2个栈顶元素计算，并将结果入栈
            // 3、建树

            m++;
            op[m] = s[i];
            // 取2个操作数
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            // 计算结点的值
            if (s[i] == '&')
                num[m] = num[x] & num[y];
            else if (s[i] == '|')
                num[m] = num[x] | num[y];
            st.push(m);
            // 建边
            add(m, x);
            add(m, y);
        }
    }

    int ans = num[st.top()];  // 整个表达式的结果
    // cout<<ans;
    // 深搜求哪些结点的值修改后对结果有影响
    dfs(st.top());  // 从根开始深搜

    // q次询问
    int q;
    cin >> q;
    while (q--)
    {
        scanf("%d", &x);
        if (book[x])
            printf("%d\n", !ans);
        else
            printf("%d\n", ans);
    }

    return 0;
}
