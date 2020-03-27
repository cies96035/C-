#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,P,C,t,u;
    cin>>N>>P>>C;
    bool k[14],flag=0;
    int tree[P];
    memset(tree,0,sizeof(tree));
    memset(k,0,sizeof(k));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<P;j++)
        {
            cin>>t;
            tree[j]+=t;
        }
    }
    for(int i=0;i<P;i++)
    {
    	//將i種類的樹木轉為二進位t
    	//當二進位t的第u位，如果k[u]是1，變為0，是0，變1 
        t=tree[i],u=0;
        while(t)
        {
            if(t%2)
            {
                k[u]=!k[u];
            }
            t/=2;
            u++;
        }
    }
    //判斷現階段是安全殘局，或者不是 
    for(int i=0;i<14;i++)if(k[i]==1)flag=1;
    
    //如果是不是安全殘局和先手關係 
    if((flag==1&&C==0)||(flag==0&&C==1))
        cout<<"Holly Win!"<<endl;
    else
        cout<<"Ivy Win!"<<endl;
        
    
    return 0;
}
