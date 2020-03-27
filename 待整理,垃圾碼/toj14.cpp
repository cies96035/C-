#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

//TM=Thousand Million=�d�U=10^9,ERR=����ull���쪺��(10^18) 
const unsigned long long TM=1000000000,TM2=TM*TM,ERR=1000000000000000000,LEN=9;

//bignum �A�x�s�C�E�Ӧ�ƪ��Ȧ@22223��(200000��)�A�M�����Ψ�n����m 
struct bignum
{
    long long n[23000],len;//�C��n�s�E�Ӧ��  len�Ʀr����
};

//�Nstr�ഫ��bignum
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

//��Ӥj�Ƭۭ� 
bignum bignummul(bignum a,bignum b)
{
    bignum c;
    memset(c.n,0,sizeof(c.n));
    c.len=a.len+b.len;//a*b=c�Ac����Ƴ̦h��a�����+b����� 
    for(int i=0;i<a.len;i++)//��Ƭۭ�
        for(int j=0;j<b.len;j++)
        {
            c.n[i+j]+=a.n[i]*b.n[j];
            if(c.n[i+j]>=ERR)//**�`�N**�S�����B�z�Y��c.n[i+j]�̫�|�[�췸�� 
            {
                c.n[i+j+2]+=c.n[i+j]/TM2;
                c.n[i+j]%=TM2;
            }
        }
    for(int i=0;i<c.len;i++)//�W�L10^9���i��,�d�U�ѤU��
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

//���B�za<b�����p 
bignum bignumminus (bignum a,bignum b)
{
	for(int i=0;i<a.len;i++)
		a.n[i]-=b.n[i];
	for(int i=0;i<a.len;i++)
		if(a.n[i]<0)
		{
			a.n[i]+=TM;
			a.n[i+1]--;
		}
	while(!a.n[a.len]&&a.len>0)a.len--;
    a.len+=1; 
	return a;
}


//��Xbignum
void coutbignum (bignum a)
{
    cout<<a.n[a.len-1];//�b�ۭ��ɧ�e�ɹs�����F�A������X�Ĥ@�ӴN�n
    for(int i=a.len-2;i>=0;i--)
        cout<<setfill('0')<<setw(LEN)<<a.n[i];//�p�G��n����9��ơA�h�n��0��9�ӼƦr 
    cout<<endl;
    return ;
}

bignum bignummod (bignum a,long long M)
{
	bignum b,m;
	memset(b.n,0,sizeof(b.n));
	memset(m.n,0,sizeof(m.n));
	b.len=a.len;
	long long r=0;
	for(int i=a.len-1;i>=0;i--)
	{
		r=r*TM+a.n[i];//TM�Ӥj�ɡAr�i��|���� 
		b.n[i]=r/M;
		r%=M;
	}
	int i=0;
	while(M)
	{
		m.n[i]=M%TM;
		M/=TM;
		i++;
	}
	m.len=i;
	b=bignummul(b,m);
	b=bignumminus(a,b);
	return b;
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
