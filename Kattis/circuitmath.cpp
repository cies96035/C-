#include<iostream>
#include<stack>
using namespace std;

#define alpha_to_num(x) (x - 'A')
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    stack<bool> num;
    bool Table[26];
    int t;
    char c;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> c;
        Table[i] = (c == 'T' ? 1 : 0);
    }
    while(cin >> c)
    {
        if('A' <= c && c <= 'Z')
            num.push( Table[alpha_to_num(c)] );
        else
        {
            if(c == '+')
            {
                int a = num.top();  num.pop();
                int b = num.top();  num.pop();
                num.push(a || b);
            }
            else if(c == '*')
            {
                int a = num.top();  num.pop();
                int b = num.top();  num.pop();
                num.push(a && b);
            }
            else if(c == '-')
            {
                int a = num.top();  num.pop();
                num.push(!a);
            }
        }
    }
    cout << (num.top() ? 'T' : 'F') << '\n';
    return 0;
}