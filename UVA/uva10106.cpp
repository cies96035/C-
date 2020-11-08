#include<iostream>
using namespace std;

#define maxL 1000
string num1,num2;

void inverse(string &s)
{
    for(int i=0;i<s.size()/2;i++)
        swap(s[i],s[s.size()-1-i]);
}

void multiple_and_output()
{
    inverse(num1);
    inverse(num2);
    if(num1.size()>num2.size())
        swap(num1,num2);
    int tmp[maxL]={0};
    for(int i=0;i<num1.size();i++)
    {
        for(int j=0;j<num2.size();j++)
        {
            tmp[i+j]+=(num1[i]-'0')*(num2[j]-'0');
        }
    }
    for(int i=0;i<maxL;i++)
        if(tmp[i]>10)
        {
            tmp[i+1]+=tmp[i]/10;
            tmp[i]%=10;
        }
    bool flg=1;
    for(int i=maxL-1;i>=0;i--)
    {
        if(tmp[i]!=0||!flg)
        {
            cout<<tmp[i];
            flg=0;
        }
    }
    if(flg)
        cout<<'0';
    cout<<'\n';
    return;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>num1>>num2)
    {
        multiple_and_output();
    }
    return 0;
}