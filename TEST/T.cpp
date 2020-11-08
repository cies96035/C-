#include<iostream>
#include<iomanip>
using namespace std;

int s(int &a)//a++
{
    int tmp=a;
    a=a+1;
    return tmp; 
}
int ss(int &a)//++a
{
    a=a+1;
    return a; 
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a=0;
    //cout<<s(a)<<endl;
    cout<<a++<<endl;
    a=0;
    //cout<<ss(a)<<endl;
    cout<<++a<<endl;
    
    return 0;
}