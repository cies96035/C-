#include<iostream>
using namespace std;

const int maxN=510;
int A[maxN],B[maxN];
int N,cnt,inp;
bool op;//紀錄狀態 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N)
	{
		cnt=0;//計數 
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

