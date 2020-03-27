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
		
		
		bool op=1;//狀態 
		for(int i=1;i<=N;i++)
		{
			if(op)//直的狀態 
			{
				if(i>B[A[i]])//翻轉 
				{
					op=!op;
					cnt++;
				}
			}
			//橫的狀態 
			else if(i<B[A[i]])//翻轉 
			{
				op=!op;
				cnt++;
			}
		}
		cout<<cnt<<'\n';//輸出翻轉次數 
	}
	return 0;
}

