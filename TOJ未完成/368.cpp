#include<iostream>
#include<cstring> 
using namespace std;

#define se 7

long long get_seven(long long N)
{
	long long seven=0,ten=1,front=N,end;
	int k;
    while(ten<=N)
    {
        k=front%10;
        front/=10;
        end=N%ten;
        if(k>se)
            seven+=(front+1)*ten;
        else
          	seven+=(front)*ten;
        if(k==se)seven+=end+1;
        ten*=10;
    }
    return seven;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long l,r;
    while(cin>>l>>r)
        cout<<get_seven(r)-get_seven(l-1)<<'\n';
    return 0;
}
