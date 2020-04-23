#include<iostream>
#include<cstring>
using namespace std;

//TM=Ten Million=十萬=10^7
const unsigned long long TM=100000000,TM2=TM*TM,LEN=8;

//bignum ，儲存每七個位數的值共30000個(210000位)，和長度
struct bignum
{
    unsigned long long n[28000],len;//每格n存六個位數  len數字長度
};

//將str轉換成bignum
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

//兩個大數相乘 
bignum bignummul(bignum a,bignum b)
{
    bignum c;
    c.len=a.len+b.len;//a*b=c，c的位數最多為a的位數+b的位數
    memset(c.n,0,c.len*8);
    for(int i=0;i<a.len;i++)//位數相乘
        for(int j=0;j<b.len;j++)
        {
            c.n[i+j]+=a.n[i]*b.n[j];
            if(c.n[i+j]>=TM2)
            {
                c.n[i+j+2]=c.n[i+j]/TM2;
                c.n[i+j]%=TM2;
            }
        }
    for(int i=0;i<c.len;i++)//超過10^8的進位,留下剩下的
    {
        if(c.n[i]>=TM)
        {
            c.n[i+1]+=c.n[i]/TM;
            c.n[i]%=TM;
        }
    }
    //如果有前導零，則減少到沒有前導零的長度 
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
}

//輸出bignum
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
    cin>>ka;//mul為相乘,pow為冪
    if(ka[2]=='l')//a,b相乘
    {
        string kb;
        bignum a,b;
        cin>>ka>>kb;
        strtobignum(ka,a);//將字串轉乘bignum
        strtobignum(kb,b);
        coutbignum(bignummul(a,b));//兩個bignum相乘後輸出
    }
    else //a^b
    {
        bignum a,ans;
        int b;//b<=4000，b用int可以不用做大數除法
        ans.len=ans.n[0]=1;//ans初始值為1
        cin>>ka>>b;
        strtobignum(ka,a);
        while(b)//快速冪
        {
            if(b%2==1)
                ans=bignummul(a,ans);
            a=bignummul(a,a);
            b/=2;
        }
        coutbignum(ans);//輸出答案
    }
    return 0;
}