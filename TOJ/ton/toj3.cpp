#include<iostream> 
using namespace std;

//gcd函數 *蠻常用的* 
int gcd(int a,int b)
{
    while((a%=b)&&(b%=a));
    return a+b;
} 

int main()
{
    int T,a,b;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    } 
    return 0;
}
