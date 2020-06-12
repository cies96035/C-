#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int Max=1<<12;
bool isntprime[Max];
string str;

int stringtonum(string s)
{
	int sum=0;
	for(int i=0;i<s.size();i++)
		if('a'<=s[i]&&s[i]<='z')
			sum+=s[i]-'a'+1;
		else if('A'<=s[i]&&s[i]<='Z')
			sum+=s[i]-'A'+27;
	return sum;
}

void Init_Prime()
{
	for(ll i=2;i<Max;i++)
		if(!isntprime[i]) 
			for(ll j=i*i;j<Max;j+=i)
				isntprime[j]=1;
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init_Prime();
	while(cin>>str)
	{
		if(!isntprime[stringtonum(str)])
			cout<<"It is a prime word.\n";
		else
			cout<<"It is not a prime word.\n";
	}
	return 0;
}

