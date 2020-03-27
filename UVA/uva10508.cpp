#include<iostream>
#include<algorithm>
using namespace std;

string tocmp;
bool cmp(string x,string y)
{
	for(unsigned int i=0;i<tocmp.size();i++)
	{
		if(x[i]<tocmp[i]&&y[i]>=tocmp[i])
			return false;
		else if(x[i]>=tocmp[i]&&y[i]<tocmp[i])
			return true;
	}
	return x<y;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int m,n;
	while(cin>>m>>n)
	{
		string words[m];
		for(int i=0;i<m;i++)
			cin>>words[i];
		tocmp=words[0];
		sort(words,words+m,cmp);
		cout<<tocmp<<endl;
		for(int i=1;i<m;i++)
			cout<<words[i]<<'\n';
	}
	return 0;
}

