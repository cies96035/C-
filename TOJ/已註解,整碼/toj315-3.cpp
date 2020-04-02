#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

const long long Carry=100,LEN=2;

//bignum ，儲存每二個位數的值共16個(最多32位)，和紀錄用到n的位置 
struct bignum
{
    long long n[30],len;//每格n存二個位數  len數字長度
};

//將str轉換成bignum
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

//兩個大數相乘 
bignum bignummul(bignum a,bignum b)
{
    bignum c;
    memset(c.n,0,sizeof(c.n));
    c.len=a.len+b.len;//a*b=c，c的位數最多為a的位數+b的位數 
    for(int i=0;i<a.len;i++)//位數相乘
        for(int j=0;j<b.len;j++)
        {
            c.n[i+j]+=a.n[i]*b.n[j];
		}
    for(int i=0;i<c.len;i++)//超過10^2的進位,留下剩下的
    {
        if(c.n[i]>=Carry)
        {
            c.n[i+1]+=c.n[i]/Carry;
            c.n[i]%=Carry;
        }
    }
    //如果有前導零，則減少到沒有前導零的長度 
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
}

//*注意* 不處理a<b的狀況 
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

//大數%longlong 
bignum bignummod (bignum a,long long M)
{
    bignum b,m;
    memset(b.n,0,sizeof(b.n));
    b.len=a.len;
    unsigned long long r=0;
    for(int i=a.len-1;i>=0;i--)
    {
        r=r*Carry+a.n[i];//Carry太大時，r可能會溢位，依照題目， 
        b.n[i]=r/M;
        r%=M;
    }
    longtobignum(M,m);
    b=bignummul(b,m);
    b=bignumminus(a,b);
    return b;
}

//輸出bignum
void coutbignum (bignum a)
{
    cout<<a.n[a.len-1];//在相乘時把前導零移除了，直接輸出第一個就好
    for(int i=a.len-2;i>=0;i--)
        cout<<setfill('0')<<setw(LEN)<<a.n[i];//如果該n不到9位數，則要補0到9個數字 
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