#include<iostream>
using namespace std;

const int maxN=510;
int A[maxN],B[maxN];
int N,cnt,inp;
bool op;//�������A 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N)
	{
		cnt=0;//�p�� 
		for(int i=0;i<N;i++)
		{
			cin>>inp;
			A[i]=inp;
			cin>>inp;
			B[inp]=i;
		}
		
		op=1;
		for(int i=0;i<N;i++)
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

