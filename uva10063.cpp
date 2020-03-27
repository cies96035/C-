#include<iostream>
#include<vector>
using namespace std;

//long long used [100000000];
string k;
vector<string> n;
int t,slen;

void coutans()
{
	n.push_back(k);
	cout<<k<<endl;
	for(int i=0;i<slen;i++)
	{
		for(int j=i+1;j<slen;j++)
		{
			bool flag=1;
			swap(k[i],k[j]);
			for(int u=0;u<n.size();u++)
			{
				if(n[i]==k)
				{
					swap(k[i],k[j]);
					flag=0;
				}
				cout<<'n'<<n[i]<<endl;
			}
			system("pause");
			if(flag)
			{ 
				coutans();
			}
		}
	}
	return;
}

int main()
{
	string s;
	while(cin>>s)
	{
		k=s;
		slen=s.size();
		coutans();
	}
	return 0;
}

