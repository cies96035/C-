#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    string s="abc";
    cout<<s.size()<<endl;
    cout<<sizeof(s)<<endl;
    cout<<sizeof(s+"123")<<endl;
    return 0;
}