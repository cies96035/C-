#include<iostream>
using namespace std;

int failure[100];//¬ö¿ýfailure­È 
string keyword,word;

void get_failure()
{
	int ws=word.size(),i=1,flen=0;
	failure[0] = 0;
	while(i<ws)
	{
		if(word[i]==word[flen])
			failure[i++] = ++flen;
		else
		{
			if(flen!=0)
				flen=failure[flen-1];
			else
				failure[i++]=0;
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>keyword>>N;
		while(N--)
		{
			bool flag=0;
			cin>>word;
			get_failure();
			for(unsigned int i=0,j=0;i<keyword.size();)
			{
				//cout<<i<<' '<<j<<endl;
				if(keyword[i]==word[j])
				{
					i++;
					j++;
					if(j==word.size())
					{
						flag=1;
						break;
					}
				}
				else
				{
					if(j!=0)
						j=failure[j-1];
					else 
						i++;
				}
			}
			if(flag)
				cout<<"y\n";
			else
				cout<<"n\n";
		}
	}
	return 0;
}

