#include<iostream>
#include<map> 
#include<iomanip>
using namespace std;
 
#define isnum(x) (x>='0'&&x<='9')

int t,n=0;
char c,tmp,molar[4]={'C','H','O','N'};
long double ans;
map<char,int> amount;
map<char,long double> value;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	cin.ignore();
	value['C']=12.01;
	value['H']=1.008;
	value['O']=16.00;
	value['N']=14.01;
	while(t--)
	{
		ans=tmp=0;
		for(int i=0;i<4;i++)
			amount[molar[i]]=0;
		while(cin.get(c))
		{
			if(!isnum(c))
			{
				if(tmp!=0)
				{
					if(n==0)
						amount[tmp]+=1;	
					else
						amount[tmp]+=n;
				}
				n=0;
				tmp=c;
			}
			else
				n=n*10+c-'0';
			if(c=='\n')
				break;
		}
		
		for(int i=0;i<4;i++)
			ans+=amount[molar[i]]*value[molar[i]];
			
		cout<<fixed<<setprecision(3)<<ans<<'\n';
		
	}
	return 0;
}
