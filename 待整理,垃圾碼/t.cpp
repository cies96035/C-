#include<iostream>
#include<cstring>
using namespace std;

void TLE()
{
    while(1);
}

//bignum 纗–计25000(200000)㎝
struct bignum
{
    //–n计0<=n[0]<10^8<=n[1]......
    //len计
    //计猭场だ穦磅︽びΩτTLE磷犯璶ノlong long
    unsigned long long n[26000],len;
};

//盢str a锣传ΘbignumΑ b
void strtobignum (string a,bignum &b)
{
    //砞0磷岿 
    memset(b.n,0,sizeof(b.n));
    int u=0,k;
    b.len=a.size()/8+1;
    if(a.size()%8==0) b.len--;
    if(b.len>1) k=-7;
    else k=-a.size()+1;
    
    for(int t=0,i=a.size()-1;i>=0;i--,t++)
    {
        b.n[u]=b.n[u]*10+(a[i+k]-'0');
        k+=2;
        if(t%8==7)
        {
            u++;
            if(i>8)k=-7;
            else k=-i+1;
        }
    }
    //磷岿 
    while(!b.n[b.len]&&b.len>0)b.len--;
    b.len+=1; 
    return;
}

bignum bignummul(bignum a,bignum b)
{
    bignum c;
    //砞0
    memset(c.n,0,sizeof(c.n));
    
    for(int i=0;i<a.len;i++)
    {
        for(int j=0;j<b.len;j++)
        {
            //计
            c.n[i+j]+=a.n[i]*b.n[j];
        }
    }
    
    //a*b=cc计程a计+b计
    c.len=a.len+b.len+5;
    
    for(int i=0;i<c.len;i++)
    {
        //禬筁10^8秈,痙逞
        c.n[i+1]+=c.n[i]/100000000;
        c.n[i]%=100000000;
    }
    //狦玡Τ计0玥盢搭ぶ瞷材Τ计
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
    
}

void coutbignum (bignum a)
{
    //块bignumbignummul()盢玡Τ0计矪瞶
    bool f=0;
    for(int i=a.len-1;i>=0;i--)
    {
        //埃程蔼箂ぃノ干ㄤ计璶干8计
        if(f)
        {
            if(a.n[i]<10)cout<<"0000000";
            else if(a.n[i]<100)cout<<"000000";
            else if(a.n[i]<1000)cout<<"00000";
            else if(a.n[i]<10000)cout<<"0000";
            else if(a.n[i]<100000)cout<<"000";
            else if(a.n[i]<1000000)cout<<"00";
            else if(a.n[i]<10000000)cout<<"0";
        }
           cout<<a.n[i];
        f=1;
    }
    cout<<'\n';
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    char k;
    //mul,pow经
    cin>>k>>k>>k;
    if(k=='l')//a,b
    {
        string ka,kb;
        bignum a,b;
        cin>>ka>>kb;
        //盢﹃锣bignum
        strtobignum(ka,a);
        strtobignum(kb,b);
        //ㄢbignum块
        coutbignum(bignummul(a,b));
    }
    else //a^b
    {
        bignum a,ans;
        string ka;
        int b;//b<=4000ノintぶ暗计埃猭
        ans.len=ans.n[0]=1;//ans﹍1
        cin>>ka>>b;
        strtobignum(ka,a);
        //е硉经
        while(b)
        {
            if(b%2==1)
                ans=bignummul(a,ans);
            a=bignummul(a,a);
            b/=2;
        }
        
        //块氮
        coutbignum(ans);
    }
    return 0;
}

