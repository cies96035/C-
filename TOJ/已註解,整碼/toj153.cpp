#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        long long a,b,c;//int平方會溢位，long long~~ 
        cin>>a>>b>>c;
        if(a<b)swap(a,b);//a為最大值 
        if(a<c)swap(a,c);
        if(a>=b+c)cout<<"illegal triangle"<<endl;
        else if(a*a<b*b+c*c)cout<<"obtuse triangle"<<endl;
        else if(a*a>b*b+c*c)cout<<"acute triangle"<<endl;
        else cout<<"right triangle"<<endl;
    }
    return 0;
}
