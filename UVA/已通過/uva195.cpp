#include<iostream>
#include<algorithm>
using namespace std;

#define upper(k) (k>='A'&&k<='Z')
#define lower(k) (k>='a'&&k<='z')

bool cmp(int a,int b)
{
	if(((upper(a)&&lower(b))||(upper(b)&&lower(a)))&&abs(a-b)!='a'-'A')
			a>='a'?a+='A'-'a':b+='A'-'a';
	return a<b;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	string comb;
	cin>>n;
	while(n--)
	{
		cin>>comb;
		sort(comb.begin(),comb.end(),cmp);
		do
		{
			cout<<comb<<'\n';
		}while(next_permutation(comb.begin(),comb.end(),cmp));
	}
	return 0;
}

