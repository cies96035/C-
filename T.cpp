#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N,L,Cmp,ans;
inline bool cmp(string x,string y)
{
    return x<y;
}
inline bool tcmp(string x,string y)
{
    x.assign(x,0,Cmp);
    y.assign(y,0,Cmp);
    return x!=y;
}
void c(string x[],string device[],int i,int a)
{    
    string plug[N];
    //cout<<plug<<endl;
    for(int j=0;j<N;j++)
        plug[j]=x[j];
    if(i==L)
    {
        Cmp=i;
        sort(plug,plug+N,cmp);
        for(int j=0;j<N;j++)
            if(tcmp(plug[j],device[j]))return;
        ans=min(ans,a);
        return;
    }
    int p_zero=0,d_zero=0,p_one;
    for(int j=0;j<N;j++)
    {
        //cout<<plug[j][i]<<' '<<device[j][i]<<endl;
        if(plug[j][i]=='0')p_zero++;
        if(device[j][i]=='0')d_zero++; 
    }
    sort(plug,plug+N);
    //cout<<a<<' '<<i<<endl;for(int k=0;k<N;k++)cout<<plug[k]<<'.';cout<<endl;
    p_one=N-p_zero;
    //cout<<d_zero<<p_zero<<p_one<<endl;
    if(d_zero==p_zero)
    {
        Cmp=i;
        //cout<<'D'<<endl;
        sort(plug,plug+N,cmp);
        //for(int k=0;k<N;k++)cout<<plug[k]<<'.';cout<<endl;for(int k=0;k<N;k++)cout<<device[k]<<' ';cout<<endl;
        int j=-1;
        while(++j<N)
            if(tcmp(plug[j],device[j]))break;
        if(j==N)
            c(plug,device,i+1,a);
    }
    if(d_zero==p_one)
    {
        Cmp=i;
        //cout<<'C'<<i<<endl;
        //cout<<'C'<<endl;
        //for(int j=0;j<N;j++)cout<<plug[j]<<endl;
        for(int j=0;j<N;j++)plug[j][i]=(plug[j][i]=='0' ? '1' : '0');
        sort(plug,plug+N,cmp);
        for(int j=0;j<N;j++)
            if(tcmp(plug[j],device[j]))return;
        c(plug,device,i+1,a+1);
    }
    //cout<<'E'<<endl;
    return;
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
        sort(device,device+N);
        c(plug,device,0,0);
        
        cout<<"Case #"<<++Case<<": ";
        (ans!=100 ? cout<<ans<<'\n' : cout<<"IMPOSSIBLE\n");
    }
    return 0;
}
