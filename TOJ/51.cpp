//暴力破解即可
//大小寫相同!!! 
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<string> pali;
string s,tofind;

bool ispali(int l,int r)//判斷l~r是否為回文 
{
	while(l<r)
		if(s[l++]!=s[r--])return 0;
	return 1;
}

bool cmp(string x,string y)
{
	return (x.size()!=y.size()) ? (x.size()<y.size()) : (x<y);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n>>s;
	tofind.append(n,(char)0);
	for(int i=0;i<s.size();i++)
		if(s[i]>='A'&&s[i]<'Z')s[i]+='a'-'A';
	
	for(int i=0;i<s.size();i++)//掃過的長度
		for(int start=0,end=start+i;end<s.size();start++,end++)//掃過的起點和終點 
			if(ispali(start,end))
				pali.push_back(s.substr(start,i+1));
				
	sort(pali.begin(),pali.end(),cmp);
	pali.resize(unique(pali.begin(),pali.end())-pali.begin());
	cout<<pali.size()<<'\n'<<pali.end()-lower_bound(pali.begin(),pali.end(),tofind,cmp)<<'\n';
	return 0;
}
