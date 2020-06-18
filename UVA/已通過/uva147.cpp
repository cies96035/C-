#include<iostream>
#include<iomanip>
using namespace std;

#define dollarsize 11
#define Maxnumber 6100
typedef unsigned long long ull;

//11 kinds value
int dollar[dollarsize]=
{5,10,20,50,100,200,500,1000,2000,5000,10000};
ull way[Maxnumber];//collect dollars ways amount
string N;

int tonum(string s)
{
	int num=0;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			num=num*10+s[i]-'0';
	return num;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	way[0]=1;
	
	for(int i=0;i<dollarsize;i++)
		dollar[i]/=5;
		
	for(int i=0;i<dollarsize;i++)
		for(int j=dollar[i];j<Maxnumber;j++)
			way[j]+=way[j-dollar[i]];

	while(cin>>N&&N!="0.00")
		cout<<setw(6)<<N<<setw(17)<<way[tonum(N)/5]<<'\n';
	
	return 0;
}

