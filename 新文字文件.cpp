#include<iostream>
#include<cstring>
using namespace std;

//TM=Ten Million=�Q�U=10^7
const unsigned long long TM=100000000,TM2=TM*TM,LEN=8;

//bignum �A�x�s�C�C�Ӧ�ƪ��Ȧ@30000��(210000��)�A�M����
struct bignum
{
    unsigned long long n[28000],len;//�C��n�s���Ӧ��  len�Ʀr����
};

//�Nstr�ഫ��bignum
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

//��Ӥj�Ƭۭ� 
bignum bignummul(bignum a,bignum b)
{
    bignum c;
    c.len=a.len+b.len;//a*b=c�Ac����Ƴ̦h��a�����+b�����
    memset(c.n,0,c.len*8);
    for(int i=0;i<a.len;i++)//��Ƭۭ�
        for(int j=0;j<b.len;j++)
        {
            c.n[i+j]+=a.n[i]*b.n[j];
            if(c.n[i+j]>=TM2)
            {
                c.n[i+j+2]+=c.n[i+j]/TM2;
                c.n[i+j]%=TM2;
            }
        }
    for(int i=0;i<c.len;i++)//�W�L10^8���i��,�d�U�ѤU��
    {
        if(c.n[i]>=TM)
        {
            c.n[i+1]+=c.n[i]/TM;
            c.n[i]%=TM;
        }
    }
    //�p�G���e�ɹs�A�h��֨�S���e�ɹs������ 
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
}

//��Xbignum
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
    cin>>ka;//mul���ۭ�,pow����
    if(ka[2]=='l')//a,b�ۭ�
    {
        string kb;
        bignum a,b;
        cin>>ka>>kb;
        strtobignum(ka,a);//�N�r���୼bignum
        strtobignum(kb,b);
        coutbignum(bignummul(a,b));//���bignum�ۭ����X
    }
    else //a^b
    {
        bignum a,ans;
        int b;//b<=4000�Ab��int�i�H���ΰ��j�ư��k
        ans.len=ans.n[0]=1;//ans��l�Ȭ�1
        cin>>ka>>b;
        strtobignum(ka,a);
        while(b)//�ֳt��
        {
            if(b%2==1)
                ans=bignummul(a,ans);
            a=bignummul(a,a);
            b/=2;
        }
        coutbignum(ans);//��X����
    }
    return 0;
