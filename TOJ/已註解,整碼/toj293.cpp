#include<iostream>
using namespace std;

//�̤j���]�� 
int gcd(int x,int y)
{
    while((x%=y)&&(y%=x));
    return x+y;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    unsigned long long a,b,x,y,t;//�ȷ���}�j�I 
    while(cin>>a>>b>>x>>y)
    {
    	//�Nx,y�����A�קKx,y>a,b�ɭP���G�X�������p 
        t=gcd(x,y);
        x/=t;
        y/=t;
        
        t=min((a/x),(b/y));
        cout<<t*x<<' '<<t*y<<'\n';
        
    }
    return 0;
}
