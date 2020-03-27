#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

const long long Carry=100,LEN=2;

//bignum 纗–计16(程32)㎝魁ノn竚 
struct bignum
{
    long long n[30],len;//–n计  len计
};

//盢str锣传Θbignum
void strtobignum (string a,bignum &b)
{
    int u=0,k;
    b.n[0]=0;
    b.len=a.size()/LEN+1;
    if(a.size()==0) b.len--;
    if(b.len>1) k=-LEN+1;
    else k=-a.size()+1;
    for(int t=0,i=a.size()-1;i>=0;i--,t++)
    {
        b.n[u]=b.n[u]*10+(a[i+k]-'0');
        k+=2;
        if(t%LEN==(LEN-1))
        {
            u++;
            b.n[u]=0;
            if(i>LEN)k=-LEN+1;
            else k=-i+1;
        }
    }
    return ;
}

void longtobignum (long long a,bignum &b)
{
	int i=0;
	while(a)
    {
        b.n[i]=a%Carry;
        a/=Carry;
        i++;
    }
    b.len=i;
}

//ㄢ计 
bignum bignummul(bignum a,bignum b)
{
    bignum c;
    memset(c.n,0,sizeof(c.n));
    c.len=a.len+b.len;//a*b=cc计程a计+b计 
    for(int i=0;i<a.len;i++)//计
        for(int j=0;j<b.len;j++)
        {
            c.n[i+j]+=a.n[i]*b.n[j];
		}
    for(int i=0;i<c.len;i++)//禬筁10^2秈,痙逞
    {
        if(c.n[i]>=Carry)
        {
            c.n[i+1]+=c.n[i]/Carry;
            c.n[i]%=Carry;
        }
    }
    //狦Τ玡旧箂玥搭ぶ⊿Τ玡旧箂 
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
}

//*猔種* ぃ矪瞶a<b猵 
bignum bignumminus (bignum a,bignum b)
{
    for(int i=0;i<a.len;i++)
        a.n[i]-=b.n[i];
    for(int i=0;i<a.len;i++)
        if(a.n[i]<0)
        {
            a.n[i]+=Carry;
            a.n[i+1]--;
        }
    while(!a.n[a.len]&&a.len>0)a.len--;
    a.len+=1; 
    return a;
}

//计%longlong 
bignum bignummod (bignum a,long long M)
{
    bignum b,m;
    memset(b.n,0,sizeof(b.n));
    b.len=a.len;
    unsigned long long r=0;
    for(int i=a.len-1;i>=0;i--)
    {
        r=r*Carry+a.n[i];//Carryびr穦犯ㄌ酚肈ヘ 
        b.n[i]=r/M;
        r%=M;
    }
    longtobignum(M,m);
    b=bignummul(b,m);
    b=bignumminus(a,b);
    return b;
}

//块bignum
void coutbignum (bignum a)
{
    cout<<a.n[a.len-1];//р玡旧箂簿埃钡块材碞
    for(int i=a.len-2;i>=0;i--)
        cout<<setfill('0')<<setw(LEN)<<a.n[i];//狦赣nぃ9计玥璶干09计 
    cout<<endl;
    return ;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        string A;
        long long B,M;
        bignum a,ans={{1},1};
        cin>>A>>B>>M;
        strtobignum(A,a);
        while(B)
        {
            if(B%2)
            {
                ans=bignummul(ans,a);    
                ans=bignummod(ans,M);
            }
            a=bignummul(a,a);
            a=bignummod(a,M);
            B/=2;
        }
        coutbignum(ans);
    }
    return 0;
}
