//得用其他演算法，不然很難再快了 


#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

//TM=Thousand Million=千萬=10^9,ERR=接近ll溢位的值(10^18) 
const unsigned long long M=100000000,M2=M*M,ERR=M2*100,LEN=8,LEN1=LEN-1;

//bignum ，儲存每八個位數的值共20個(100位)，和紀錄用到n的位置 
struct bignum
{
    long long n[20],len;//每格n存八個位數  len數字長度
};

//將str轉換成bignum
void strtobignum (string a,bignum &b)
{
    int u=0,k;
    b.n[0]=0;
    b.len=a.size()/LEN+1;
    if(a.size()==0) b.len--;
    if(b.len>1) k=-LEN1;
    else k=-a.size()+1;
    for(int t=0,i=a.size()-1;i>=0;i--,t++)
    {
        b.n[u]=b.n[u]*10+(a[i+k]-'0');
        k+=2;
        if(t%LEN==LEN1)
        {
            u++;
            b.n[u]=0;
            if(i>LEN)k=-LEN1;
            else k=-i+1;
        }
    }
    return ;
}

//-1 a>b 0 a=b 1 a<b
int bignumjudge(bignum a,bignum b)
{
	if(b.len>a.len)//後面比較長 
		return 1;
	else if(b.len==a.len)//一樣長度一一比較位數 
	{
		int digits=a.len;
		while(--digits>=0)
		{
			if(b.n[digits]>a.n[digits])
				return 1; 
			if(b.n[digits]<a.n[digits])
				return -1;
		}
		return 0;
	}
}

//兩個大數相加
bignum bignumadd(bignum a,bignum b)
{
	bignum c;
	memset(c.n,0,sizeof(c.n));
	c.len=max(a.len,b.len)+1;
	for(int i=0;i<c.len;i++)
	{
		c.n[i]+= (i<a.len?a.n[i]:0) +  (i<b.len?b.n[i]:0)  ;
		if(c.n[i]>=M)
		{
			c.n[i]-=M;
			c.n[i+1]++;
		}
	}
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
}
 
//兩個大數相減 
bignum bignummin(bignum a,bignum b)
{	
	//先比較大小
	if(bignumjudge(a,b))
	{
		swap(a,b);
		cout<<'-';
	}
	bignum c;
	memset(c.n,0,sizeof(c.n));
	c.len=a.len;
	for(int i=0;i<c.len;i++)
	{
		c.n[i]+= a.n[i] -  (i<b.len?b.n[i]:0)  ;
		if(c.n[i]<0)
		{
			c.n[i]+=M;
			c.n[i+1]--;
		}
	}
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
	return c;
	 
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
            if(c.n[i+j]>=ERR)//**注意**沒有此處理某個c.n[i+j]最後會加到溢位 
            {
                c.n[i+j+2]+=c.n[i+j]/M2;
                c.n[i+j]%=M2;
            }
        }
    for(int i=0;i<c.len;i++)//超過10^9的進位,留下剩下的
    {
        if(c.n[i]>=M)
        {
            c.n[i+1]+=c.n[i]/M;
            c.n[i]%=M;
        }
    }
    //如果有前導零，則減少到沒有前導零的長度 
    while(!c.n[c.len]&&c.len>0)c.len--;
    c.len+=1; 
    return c;
}


//兩個大數相除 
bignum bignumdiv(bignum a,bignum b)
{
	bignum c,nums[10],i;
	memset(c.n,0,sizeof(c.n));
	c.len=a.len-b.len+1;
	for(i.len=i.n[0]=0;i.n[0]<10;i.n[0]++)
		nums[i.n[0]]=bignummul(b,i);
	for(int i=c.len;i>=0;i--)
	{
		for(int j=9;j>=0;j--)
		{
			if(pow(10,c.len)*b<a)
			a-=pow(10,c.len)
			c[i]=j;
			break;
		}
	}
} 

//輸出bignum
void coutbignum (bignum a)
{
    cout<<a.n[a.len-1];//在相乘時把前導零移除了，直接輸出第一個就好
    for(int i=a.len-2;i>=0;i--)
        cout<<setfill('0')<<setw(LEN)<<a.n[i];//如果該n不到8位數，則要補0到8個數字 
    cout<<endl;
    return ;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    while(n--)
    {
    	bignum ans,num;
    	string num1,num2;
    	char oper;
    	cin>>num1>>oper>>num2;
    	strtobignum(num1,ans);
    	strtobignum(num2,num);
    	if(oper=='+')
    		coutbignum(bignumadd(ans,num));
    	else if(oper=='-')
    		coutbignum(bignummin(ans,num));
    	else if(oper=='*')
    		coutbignum(bignummul(ans,num));
    	else if(oper=='/')
    	{
    		
		}
		else
			cout<<bignumjudge(ans,num)<<endl;
	}
    return 0;
}
