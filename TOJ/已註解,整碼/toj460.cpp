#include<iostream>
using namespace std;

const int s=3,N=s*s;//size
typedef pair<int,int> pii;

pii PL[N],NP;//������N�I��Place 
int  Cp[N],tb[s][s],cnt=0;//Camp�O���U�s�����A(-1,0,1)�ATable�������� 
int m[4][2]={{-1,0},{0,-1},{0,1},{1,0}};//���ܹj���I 
int NPid;//�����j���Inextpoint����m�A�H�ΥL���s�� 
bool Cpid=0; //�}��id 
string P[N]; //�����W�U���k��O Power 
string inputmp;//��J�Ȧs 

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
		Cp[i]=-1;//��l��
		
	for(int i=0;i<N;i++)
	{
		Cp[i]=Cpid;
		for(int j=0,jj=3;j<4;j++,jj--)
		{
			NP=pii(PL[i].first+m[j][0],PL[i].second+m[j][1]);
			NPid=tb[NP.first][NP.second];
			//�p�G�P�}��ΨS�}��or�X�� 
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

