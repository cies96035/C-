#include<iostream> 
#include<iomanip>
using namespace std;

typedef long double ld;
string A,B;
ld lovevalue;

int digit_sum(int x)
{
	int sum=0;
	while(x)
	{
		sum+=x%10;
		x/=10;
	}
	return sum;
}

ld string_to_lovevalue(string x)
{
	int value=0;
	for(int i=0;i<x.size();i++)
	{
		if('a'<=x[i]&&x[i]<='z')
			value+=x[i]-'a'+1;
		if('A'<=x[i]&&x[i]<='Z')
			value+=x[i]-'A'+1;
	}
	while(value>9)
		value=digit_sum(value);
	return value;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(getline(cin,A))
	{
		getline(cin,B);
		lovevalue=string_to_lovevalue(B)/string_to_lovevalue(A);
		if(lovevalue>1)
			lovevalue=1/lovevalue;
		cout<<fixed<<setprecision(2)<<lovevalue*100<<" %\n";
	}
	return 0;
}
