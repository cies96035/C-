#include<iostream>
#include<cstring>
using namespace std;

#define Max 1010
#define Num 10
int N,k,Game=1;
int pswd[Max],gss[Max],A[Num],B[Num],R[Num];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N&&N)
	{
		//Initial
		memset(R,0,sizeof(R));
		
		//input
		for(int i=0;i<N;i++)
		{
			cin>>pswd[i];
			R[pswd[i]]++;
		}
		
		//output
		cout<<"Game "<<Game++<<":\n";
		
		while(true)
		{
			//Initial
			int a=0,b=0;
			memset(A,0,sizeof(A));
			memset(B,0,sizeof(B));
			
			//input
			for(int i=0;i<N;i++)
				cin>>gss[i];
			if(gss[0]==0)
				break;
				
			//check amount of each numbers' A,B
			for(int i=0;i<N;i++)
			{
				k=gss[i];
				if(pswd[i]==k)
				{
					A[k]++;
					if(R[k])
						R[k]--;
					else
						B[k]--;
				}
				else if(R[k])
				{
					R[k]--;
					B[k]++;
				}
			}
			
			//get total a and b,and make R to original
			for(int i=0;i<Num;i++)
			{
				a+=A[i];
				b+=B[i];
				R[i]+=A[i]+B[i];
			}
			
			//output
			cout<<"    ("<<a<<','<<b<<")\n";
		}
	}
	return 0;
}
