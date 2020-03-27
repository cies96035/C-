#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;

int N,L,Cmp,ans=100;
bool cmp(string x,string y)
{
    x.assign(x,0,Cmp);
    y.assign(y,0,Cmp);
    return x<y;
}
bool tcmp(string x,string y)
{
    x.assign(x,0,Cmp);
    y.assign(y,0,Cmp);
    return x!=y;
}
void c(string plug[],string device[],int i,int a,int b)
{
    Cmp=i;
    if(i==L)
    {
        ans=min(ans,min(a,b));
        return;
    }
    int p_zero=0,d_zero=0,p_one;
    for(int j=0;j<N;j++)
    {
        //cout<<plug[j][i]<<' '<<device[j][i]<<endl;
        if(plug[j][i]=='0')p_zero++;
        if(device[j][i]=='0')d_zero++; 
    }
    p_one=N-p_zero;
    if(d_zero==p_zero)
    {
        sort(plug,plug+N,cmp);
        sort(device,device+N,cmp);
        //for(int k=0;k<N;k++)cout<<plug[k]<<'.';cout<<endl;
        //for(int k=0;k<N;k++)cout<<device[k]<<' ';cout<<endl;
        for(int j=0;j<N;j++)
            if(tcmp(plug[j],device[j]))return;
        c(plug,device,i+1,a,b+1);
    }
    if(d_zero==p_one)
    {
        //for(int k=0;k<N;k++)cout<<plug[k]<<'*';cout<<endl;
        for(int j=0;j<N;j++)plug[j][i]=(plug[j][i]=='0' ? '1' : '0');
        //for(int k=0;k<N;k++)cout<<plug[k]<<'/';cout<<endl;
        sort(plug,plug+N,cmp);
        sort(device,device+N,cmp);
        //for(int k=0;k<N;k++)cout<<plug[k]<<'.';cout<<endl;
        //for(int k=0;k<N;k++)cout<<device[k]<<' ';cout<<endl;
        //cout<<Cmp<<endl;
        for(int j=0;j<N;j++)
            if(tcmp(plug[j],device[j]))return;
        c(plug,device,i+1,a+1,b);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    cin>>T;
    for(int Case=0;Case<T;)
    {
        ans=100;
        cin>>N>>L;
        string plug[N],device[N];
        
        for(int i=0;i<N;i++)
            cin>>plug[i];
        for(int i=0;i<N;i++)
            cin>>device[i];
        c(plug,device,0,0,0);
        
        cout<<"Case #"<<++Case<<": ";
        (ans!=100 ? cout<<ans<<'\n' : cout<<"IMPOSSIBLE\n");
    }
    return 0;
}
