#include<iostream>
#include<map>
using namespace std;

#define Maxn 1100

int DNAamount[4][Maxn],t,m,n,sum;
char DNA,id_to_char[4]={'A','C','G','T'};
map<char,int> char_to_id;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//Init 
	char_to_id['A']=0;
	char_to_id['C']=1;
	char_to_id['G']=2;
	char_to_id['T']=3;
	
	cin>>t;//test amount
	
	while(t--)
	{
		//Init
		sum=0;
		
		cin>>m>>n;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>DNA;
				DNAamount[char_to_id[DNA]][j]++;
			}
			
		for(int i=0;i<n;i++)
		{
			int Max=DNAamount[0][i],Maxid=0;
			for(int j=0;j<4;j++)
			{
				if(DNAamount[j][i]>Max)
					Max=DNAamount[j][i],Maxid=j;
				DNAamount[j][i]=0;
			}
			cout<<id_to_char[Maxid];
			sum+=m-Max;
		}
		
		cout<<'\n'<<sum<<'\n';
	}
	return 0;
}

