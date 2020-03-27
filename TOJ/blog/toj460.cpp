#include<iostream>
using namespace std;

const int s=3,N=s*s;//size
typedef pair<int,int> pii;

pii PL[N],NP;//紀錄第N點的Place 
int  Cp[N],tb[s][s],cnt=0;//Camp記錄各編號狀態(-1,0,1)，Table紀錄版面 
int m[4][2]={{-1,0},{0,-1},{0,1},{1,0}};//移至隔壁點 
int NPid;//紀錄隔壁點nextpoint的位置，以及他的編號 
bool Cpid=0; //陣營id 
string P[N]; //紀錄上下左右能力 Power 
string inputmp;//輸入暫存 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i=0;i<s;i++)
	{
		cin>>inputmp;
		for(int j=0;j<s;j++)
		{
			tb[i][j]=inputmp[j]-'0';
			PL[tb[i][j]]=pii(i,j);
		}
	}
	for(int i=0;i<N;i++) 
		cin>>P[i];
	for(int i=0;i<N;i++)
		Cp[i]=-1;//初始化
		
	for(int i=0;i<N;i++)
	{
		Cp[i]=Cpid;
		for(int j=0,jj=3;j<4;j++,jj--)
		{
			NP=pii(PL[i].first+m[j][0],PL[i].second+m[j][1]);
			NPid=tb[NP.first][NP.second];
			//如果同陣營或沒陣營or出界 
			if(NP.first<0||NP.first==s||NP.second<0||NP.second==s||Cp[NPid]!=!Cpid)
				continue;
			if(P[i][j]>=P[NPid][jj])
				Cp[NPid]=Cpid;
		}
		Cpid=!Cpid;
	}
	
	for(int i=0;i<N;i++)
		if(Cp[i])cnt++;
	cout<<N-cnt<<'-'<<cnt<<'\n';
	
	return 0;
}

