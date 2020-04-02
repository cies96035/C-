#include<iostream>
using namespace std;

long long gcd(long long a,long long b)
{
    while((a%=b)&&(b%=a));
    return a+b;
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    //輸入格式為(四個字元)(整數)(一個字元)(整數)(一個字元)
    char c,C;//c判斷用，C滿足上述格式用
    long long a,b;
    while(cin>>c>>C>>C>>C>>a>>C>>b>>C)
    {
        //GCD ( a , b )
        if(c=='G')cout<<gcd(a,b)<<'\n';
        //LCM ( a , b )
        else if(c=='L')cout<<lcm(a,b)<<'\n';
        //ADD ( a , b )
        else if(c=='A')cout<<a+b<<'\n';
        //SUB ( a , b )
        else if(c=='S')cout<<a-b<<'\n';
        //MUL ( a , b ) 
        else if(c=='M')cout<<a*b<<'\n';
        //DIV ( a , b )
        else if(c=='D')cout<<a/b<<'\n';
    } 
    return 0;
}
