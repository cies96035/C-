#include<iostream>
using namespace std;

const int N=1<<3,M=1<<N;
string S;
char c;
int len,num; 
int ID[N+1][M];//value [len][value]=id e.x.(000)->len=3,value=0

void Init()//table the value
{
	int id=0;//the id
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<(1<<i)-1;j++)//0...0 ~ 1...1 -1
			ID[i][j]=id++;
		ID[i][(1<<i)-1]=-1;//break flag,if all bit is 1
	}
	return;
}

int getcode(int l)//get l'length string, turn it to a number base two
{
	int n=0;
	while(l--)
	{
		cin>>c;
		n=(n<<1)+c-'0';
	}
	return n;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init();
	
	while(getline(cin,S))
	{
		len=-1;//Init
		while(true)//until the len is zero(000),then break
		{
			if(len==-1)//we need a pswd len
			{
				len=getcode(3);//a new pswd len by three char
				if(!len)//if code length is zero(000),means break
					break;
			}
			else
			{
				num=getcode(len);//get len char
				if(ID[len][num]==-1)//if all char is 1,than continue with next code
					len=-1;
				else
					cout<<S[ID[len][num]];
			}
		}
		cout<<'\n';
		cin.ignore();//ignore cin's '\n'
	}
	
	return 0;
}

