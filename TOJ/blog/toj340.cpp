#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string a;
    cin>>a;
    //�r����j�g 
    if(a[0]<='z'&&a[0]>='a')a[0]+='A'-'a';
    cout<<" Nice to see you, "<<a<<"!"<<endl;
    return 0;
}
