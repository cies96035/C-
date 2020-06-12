#include<iostream>
#include<iomanip>
using namespace std;

#define MaxN 1100

int score[MaxN];//record scores in class
int t,N,sum,pass_amount;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	while(t--)
	{
		//Init
		sum=pass_amount=0;
		
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>score[i];
			sum+=score[i];
		}
		
		for(int i=0;i<N;i++)
			if(score[i]*N>sum)
				pass_amount++;
		
		cout<<fixed<<setprecision(3)<<(double)pass_amount/N*100<<"%\n";
	}
	return 0;
}

