#include<iostream>
using namespace std;
int n,m;
string str;
int index,k;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>n>>m)
	{
		
		//Init
		str="";
		int isvisited[m]={0};
		index=1,k=n%m;
		
		//until there is a cycle (visit again)
		while(!isvisited[k])
		{
			isvisited[k]=index++;
			k*=10;
			str+=k/m+'0';
			k%=m;
		}
		k=isvisited[k]-1;
		
		//output part
		cout<<n<<'/'<<m<<" = "<<
		
		//the cycle float
		n/m<<'.'<<str.substr(0,k)<<'(';
		if(str.size()>50)
			cout<<str.substr(k,50-k)<<"...";
		else
			cout<<str.substr(k,str.size()-k);
			
		//cycle length
		cout<<")\n   "<<index-k-1<<" = number of digits in repeating cycle\n\n";
	}
	return 0;
}

