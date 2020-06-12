#include<iostream>
#include<algorithm>
using namespace std;

#define N 26
#define is_upper(c) c>='A'&&c<='Z'
#define is_lower(c) c>='a'&&c<='z'

int t;
char c;
struct Alpha
{
	int id;
	int num;
}alpha[26];

bool cmp(Alpha a,Alpha b)
{
	if(a.num!=b.num)
		return a.num>b.num;
	else
		return a.id<b.id;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i=0;i<26;i++)
		alpha[i].id=i;
		
	cin>>t;
	cin.ignore();
	
	while(t)
	{
		cin.get(c);
		if(is_upper(c))
			alpha[c-'A'].num++;
		else if(is_lower(c))
			alpha[c-'a'].num++;
		else if(c=='\n')
			t--;
	}
	
	sort(alpha,alpha+N,cmp);
	
	for(int i=0;i<N;i++)
	{
		if(!alpha[i].num)
			break;
		cout<<char(alpha[i].id+'A')<<' '<<alpha[i].num<<'\n';
	}
	return 0;
}

