#include<iostream>
using namespace std;

#define same (count[0]==count[1]||count[0]==count[2]||count[0]==count[3]||count[1]==count[2]||count[1]==count[3]||count[2]==count[3])

int num[4];

inline void Init()
{
	for(int i=0;i<4;i++)num[i]=i;
}

inline void coutnum()
{
	for(int i=0;i<4;i++)cout<<num[i];
	cout<<endl;
}

inline count_to_num(int *count)
{
	for(int i=0;i<4;i++)num[i]=count[i];
}

int main()
{
	Init();
	coutnum();
	int A,B; 
	while(cin>>A>>B)
	{
		if(A==4)
		{
			Init();
			coutnum();
			continue;
		}
		int iA,iB,count[4]={0,0,0,0};
		while(count[0]<10)
		{
			iA=0,iB=0;
			
			//判斷現狀是幾A幾B
			//找出一個同樣是幾A幾B但比num大的值 
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					if(count[j]==num[i])
					{
						if(i==j)
							iA++;
						else
							iB++;
					}
					
				}
			}
			
			if(iA==A&&iB==B&&!same)break;
			count[3]++;
			if(count[3]==10)count[3]-=10,count[2]++;
			if(count[2]==10)count[2]-=10,count[1]++;
			if(count[1]==10)count[1]-=10,count[0]++;
		}
		count_to_num(count);
		coutnum();
	}
	return 0;
}

