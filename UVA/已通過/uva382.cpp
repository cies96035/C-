#include<iostream>
#include<iomanip>
using namespace std;

#define maxN 70000
int cch[maxN];
int N,sum;
void output(int n)
{
	if(cch[n]==1)
		cout<<setw(5)<<n<<"  DEFICIENT\n";
	else if(cch[n]==2)
		cout<<setw(5)<<n<<"  PERFECT\n";
	else if(cch[n]==3)
		cout<<setw(5)<<n<<"  ABUNDANT\n";
	return;
}
int main()
{
	cout<<"PERFECTION OUTPUT\n";
	while(cin>>N&&N)
	{
		if(cch[N])
			output(N); 
		else
		{
			sum=0;
			for(int i=1;i<=N/2;i++)
				if(!(N%i))
					sum+=i;
			if(sum<N)
				cch[N]=1;
			else if(sum==N)
				cch[N]=2;
			else
				cch[N]=3;
			output(N);
		}	
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}

