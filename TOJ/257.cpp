//¾÷ÙTÃD¥Ø 

#include<iostream>
#include<cstring>
using namespace std;

int gcd(int x,int y)
{
    while((x%=y)&&(y%=x));
    return x+y;
}

int LCS(string a,string b)
{
    int LCSlen[a.size()+1][b.size()+1];
    memset(LCSlen,0,sizeof(LCSlen));
	for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            if(a[i]==b[j])
                LCSlen[i+1][j+1]=LCSlen[i][j]+1;
            else
                LCSlen[i+1][j+1] = max(LCSlen[i][j+1],LCSlen[i+1][j]);
        }
    }
    return LCSlen[a.size()][b.size()];
}

string change(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A')s[i]='T';
		else if(s[i]=='T')s[i]='A';
		else if(s[i]=='C')s[i]='G';
		else if(s[i]=='G')s[i]='C';
	}
	return s;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    string a,b;
    cin>>a>>b;
    int son=max(LCS(a,b),LCS(change(a),b))*2,mom=a.size()+b.size();
    if(!son)cout<<"0/"<<mom<<'\n';
    else cout<<son/gcd(son,mom)<<'/'<<mom/gcd(son,mom)<<'\n';
    return 0;
}
