#include <iostream>
#include <stack>
using namespace std;

int pre(char x)
{
    if(x=='+'||x=='-')
        return 0;    
    if(x=='*'||x=='/')
        return 1;
    if(x=='('||x==')')
        return -1;
    return -2;//not op
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    stack<char> op;
    string preorder;
    char s;
    while(cin.get(s)&&s!='\n')
    { 
        if(pre(s)>=-1)
        {
            if(op.empty())
            {
                op.push(s);
            }
            else
            {
                if(pre(s)>pre(op.top()))
                {
                    op.push(s);
                }
                else if(pre(op.top())<=pre(s))
                {
                    preorder+=op.top();
                    op.pop();
                    op.push(s);
                }
                else if(pre(s)==-1)
                {
                    if(s==')')
                    {
                        while(op.top()!='(')
                        {
                            preorder+=op.top();
                            op.pop();
                        }
                        op.pop();
                    }
                    else
                    {
                        op.push(s);
                    }
                    
                }
                else
                {
                    op.push(s);
                }
            }
        }
        else
        {
            preorder+=s;
        }
        
    }
    while(!op.empty())
    {   
        preorder+=op.top();
        op.pop();
    }
    cout<<preorder<<endl;

    stack<int> num;
    for(int i=0;i<preorder.size();i++)
    {
        if('0'<=preorder[i]&&preorder[i]<='9')
            num.push(preorder[i]-'0');
        else
        {
            int b=num.top();
            num.pop();
            int a=num.top();
            num.pop();
            switch(preorder[i])
            {
                case '+':
                    num.push(a+b);
                    break;
                case '-':
                    num.push(a-b);
                    break;
                case '*':
                    num.push(a*b);
                    break;
                case '/':
                    num.push(a/b);
                    break;
            }
        }
    }
    cout<<num.top()<<endl;
    return 0;
}