#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

#define Max 15

struct Word
{
	int id;
	string W;
	Word(int a)
	{
		id=a;
		W="";
	}
	void Print()
	{
		cout<<setw(3)<<id<<'.'<<W<<'\n';
	}
};

int N,M,index,Puzzle=0;
char table[Max][Max];
vector<Word> Across,Down;


void Init()
{
	Down.clear();
	Across.clear();
	index=0;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//Init1
	for(int i=0;i<Max;i++)
		table[i][0]=table[0][i]='*';

	while(cin>>N&&N)
	{
		Init();//Init2
		
		//input
		cin>>M;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				cin>>table[i][j];
				
		if(Puzzle)
			cout<<'\n';
		cout<<"puzzle #"<<++Puzzle<<":\n";
		
		//get id & down/across
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				if(table[i][j]!='*')
				{
					//new id
					if(table[i-1][j]=='*'||table[i][j-1]=='*')
						index++;
						
					//Down
					if(table[i-1][j]=='*')
					{
						Down.emplace_back(Word(index));
						for(int ii=i;table[ii][j]!='*'&&ii<=N;ii++)
							Down.back().W+=table[ii][j]; 
					}
					
					//Across
					if(table[i][j-1]=='*')
					{
						Across.emplace_back(Word(index));
						for(int jj=j;table[i][jj]!='*'&&jj<=M;jj++)
							Across.back().W+=table[i][jj];
					}
				}
				
		cout<<"Across\n";
		for(int i=0;i<Across.size();i++)
			Across[i].Print();
			
		cout<<"Down\n";
		for(int i=0;i<Down.size();i++)
			Down[i].Print();
	}
	return 0;
}

