#include<iostream>
#include<cstring>
using namespace std;

//TM=Ten Million=窾=10^7
const unsigned long long TM=100000000,TM2=TM*TM,LEN=8;

//bignum 纗–计30000(210000)㎝
struct bignum
{
    unsigned long long n[28000],len;//–nせ计  len计
};

//盢str锣传Θbignum
void strtobignum (string a,bignum &b)
{
    int u=0,k;
    b.n[0]=0;
    b.len=a.size()/LEN+1;
    if(a.size()==0) b.len--;
    if(b.len>1) k=-7;
    else k=-a.size()+1;
    for(int t=0,i=a.size()-1;i>=0;i--,t++)
    {
        b.n[u]=b.n[u]*10+(a[i+k]-'0');
        k+=2;
        if(t%LEN==7)
        {
            u++;
            b.n[u]=0;
            if(i>LEN)k=-7;
            else k=-i+1;
        }
    }
    return ;
}

//ㄢ计 
bignum bignummul(bignum a,bignum b)
{
    bignum c;
    c.len=a.len+b.len;//a*b=cc计程a计+b计
    memset(c.n,0,c.len*8);
    for(int i=0;i<a.len;i++)//计
        for(int j=0;j<b.len;j++)
        {
            c.n[i+j]+=a.n[i]*b.n[j];
            if(c.n[i+j]>=TM2)
            {
                c.n[i+j+2]+=c.n[i+j]/TM2;
                c.n[i+j]%=TM2;
            }
        }
    for(int i=0;i<c.len;i++)//禬筁10^8秈,痙逞
    {
        if(c.n[i]>=TM)
        {
            c.n[i+1]+=c.n[i]/TM;
            c.n[i]%=TM;
        }
    }
    //狦Τ玡旧箂玥搭ぶ⊿Τ玡旧箂 
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
}

//块bignum
void coutbignum (bignum a)
{
    cout<<a.n[a.len-1];
    for(int i=a.len-2;i>=0;i--)
    {
        if(a.n[i]<10)cout<<"0000000";
        else if(a.n[i]<100)cout<<"000000";
        else if(a.n[i]<1000)cout<<"00000";
        else if(a.n[i]<10000)cout<<"0000";
        else if(a.n[i]<100000)cout<<"000";
        else if(a.n[i]<1000000)cout<<"00";
        else if(a.n[i]<10000000)cout<<"0";
        cout<<a.n[i];
    }
    cout<<endl;
    return ;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string ka;
    cin>>ka;//mul,pow经
    if(ka[2]=='l')//a,b
    {
        string kb;
        bignum a,b;
        cin>>ka>>kb;
        strtobignum(ka,a);//盢﹃锣bignum
        strtobignum(kb,b);
        coutbignum(bignummul(a,b));//ㄢbignum块
    }
    else //a^b
    {
        bignum a,ans;
        int b;//b<=4000bノintぃノ暗计埃猭
        ans.len=ans.n[0]=1;//ans﹍1
        cin>>ka>>b;
        strtobignum(ka,a);
        while(b)//е硉经
        {
            if(b%2==1)
                ans=bignummul(a,ans);
            a=bignummul(a,a);
            b/=2;
        }
        coutbignum(ans);//块氮
    }
    return 0;
