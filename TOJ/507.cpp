#include<iostream>
using namespace std;

const int maxN=510;
int A[maxN],B[maxN];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,cnt,a,b;
	while(cin>>N)
	{
		cnt=0;
		for(int i=1;i<=N;i++)
		{
			cin>>a>>b;
			B[b]=i;
			A[i]=a;
		}
		
		
		bool op=1;//���A 
		for(int i=1;i<=N;i++)
		{
			if(op)//�������A 
			{
				if(i>B[A[i]])//½�� 
				{
					op=!op;
					cnt++;
				}
			}
			//����A 
			else if(i<B[A[i]])//½�� 
			{
				op=!op;
				cnt++;
			}
		}
		cout<<cnt<<'\n';//��X½�স�� 
	}
	return 0;
}

