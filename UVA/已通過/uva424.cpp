#include<iostream>
using namespace std;

#define Max 110
int sum[Max];
string s;
void str_add_to_sum(string a)
{
	for(int i=a.size()-1,j=0;i>=0;i--,j++)
		sum[j]+=a[i]-'0';
	return;
}
void carry()
{
	for(int i=0;i<Max;i++)
		if(sum[i]>9)
		{
			sum[i+1]+=sum[i]/10;
			sum[i]%=10;
		}
	return;
}
void print()
{
	bool flag=0;
	for(int i=Max-1;i>=0;i--)
	{
		if(flag||sum[i])
		{
			cout<<sum[i];
			flag=1;
		}
	}
	cout<<'\n';
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>s&&s!="0")
		str_add_to_sum(s);
	carry();
	print();
	return 0;
}

