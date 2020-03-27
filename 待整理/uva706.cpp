#include<iostream>
#include<cstring>
using namespace std;

//计块妓Α╊Θき场だㄤいΤㄢ贺块よΑ 
/*
 -  场だA块よΑ:0 
| | 场だB块よΑ:1
    场だC块よΑ:0
| | 场だD块よΑ:1
 - 	场だE块よΑ:0
魁–计场だABCDE篈 

だㄌ酚篈块 
*/
int nums_to_cout[10][5]={
{1,1,0,1,1},
{0,0,0,0,0},
{1,0,1,2,1},
{1,0,1,0,1},
{0,1,1,0,0},
{1,2,1,0,1},
{1,2,1,1,1},
{1,0,0,0,0},
{1,1,1,1,1},
{1,1,1,0,1}};

string vertical_bar_part;//B,D场だ纗癬ㄓ块耞丁 
char End=' ';//耞–计挡Ю璶块临琌传︽

//硈腹场だ/计/场 
void put_hyphen(int s,int n,int k)
{
	//オ娩场だ
	cout<<' ';
	
	//い丁场だ 
	if(nums_to_cout[n][k])
		while(s--)cout<<'-';
	else
		while(s--)cout<<' ';
		
	//娩场だ+だ筳 
	cout<<' '<<End;
}

//兵计/场 
void put_vertical_bar(int s,int n,int k)
{
	if(nums_to_cout[n][k])//オ娩场だ 
		vertical_bar_part.append("|");
	else
		vertical_bar_part.append(" ");
		
	//い丁场だ 
	vertical_bar_part.append(s,' ');
	
	//娩场だ+だ筳 
	if(nums_to_cout[n][k]<2)
		vertical_bar_part.append("|");
	else
		vertical_bar_part.append(" ");
	vertical_bar_part.append(1,End);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string N;
	int s;
	while(cin>>s>>N)
	{
		if(s==0&&N=="0")return 0;
		for(int i=0;i<5;i++)//场 
		{
			for(unsigned long long j=0,Ns=N.size();j<Ns;j++)//计オ 
			{
				if(j==Ns-1)End='\n';
				if(i%2)
					put_vertical_bar(s,N[j]-'0',i);
				else
					put_hyphen(s,N[j]-'0',i);
			}
			End=' ';
			for(int j=0;j<s;j++)cout<<vertical_bar_part;
			vertical_bar_part.clear();
		}
		cout<<'\n';
	}
	return 0;
}

