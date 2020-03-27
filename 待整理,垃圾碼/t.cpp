#include<iostream>
#include<cstring>
using namespace std;

void TLE()
{
    while(1);
}

//bignum �A�x�s�C�K�Ӧ�ƪ��Ȧ@25000��(200000��)�A�M����
struct bignum
{
    //�C��n�s�K��ơA0<=n[0]<10^8<=n[1]......
    //len�Ʀr����
    //�u�s�@�Ӧ�Ʀb���k�����|����Ӧh����TLE�A�קK����n��long long
    unsigned long long n[26000],len;
};

//�Nstr a�ഫ��bignum�Φ� b
void strtobignum (string a,bignum &b)
{
    //���]��0�קK�X�� 
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
    //�קK�X�� 
    while(!b.n[b.len]&&b.len>0)b.len--;
    b.len+=1; 
    return;
}

bignum bignummul(bignum a,bignum b)
{
    bignum c;
    //���]��0
    memset(c.n,0,sizeof(c.n));
    
    for(int i=0;i<a.len;i++)
    {
        for(int j=0;j<b.len;j++)
        {
            //��Ƭۭ�
            c.n[i+j]+=a.n[i]*b.n[j];
        }
    }
    
    //a*b=c�Ac����Ƴ̦h��a�����+b�����
    c.len=a.len+b.len+5;
    
    for(int i=0;i<c.len;i++)
    {
        //�W�L10^8���i��,�d�U�ѤU��
        c.n[i+1]+=c.n[i]/100000000;
        c.n[i]%=100000000;
    }
    //�p�G�e��������Ƭ�0�A�h�N���״�֡A����X�{�Ĥ@�Ӧ��Ȫ����
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
    
}

void coutbignum (bignum a)
{
    //��Xbignum�A�bbignummul()�w�N�e����0����ƳB�z�F
    bool f=0;
    for(int i=a.len-1;i>=0;i--)
    {
        //���F�̰��쪺�s���θɡA��L��ƭn�ɨ�8�ӼƦr
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
    //mul���ۭ�,pow����
    cin>>k>>k>>k;
    if(k=='l')//a,b�ۭ�
    {
        string ka,kb;
        bignum a,b;
        cin>>ka>>kb;
        //�N�r���୼bignum
        strtobignum(ka,a);
        strtobignum(kb,b);
        //���bignum�ۭ����X
        coutbignum(bignummul(a,b));
    }
    else //a^b
    {
        bignum a,ans;
        string ka;
        int b;//b<=4000�A��int�i�H�ְ��j�ư��k
        ans.len=ans.n[0]=1;//ans��l�Ȭ�1
        cin>>ka>>b;
        strtobignum(ka,a);
        //�ֳt��
        while(b)
        {
            if(b%2==1)
                ans=bignummul(a,ans);
            a=bignummul(a,a);
            b/=2;
        }
        
        //��X����
        coutbignum(ans);
    }
    return 0;
}

