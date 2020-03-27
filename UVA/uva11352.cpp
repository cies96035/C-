#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T,M,N;//�����,y�b����,x�b���� 
	cin>>T;
	while(T--)
	{
		cin>>M>>N;
		char input;
		int ex,ey,sx,sy,trip[M][N];
		memset(trip,0,sizeof(trip));
		//trip�ΨӰO���q�_�I��F�Ӧa�ݭn�h�֨B��
		//0�N�����L,�i�H�e��,-1�N����e��,��l�Ʀr�N���g���L,�]����e��
		
		//�ھڿ�J�o��_�I�B���I�B�H�Τ���e������m 
		for(int i=M-1;i>=0;i--)
			for(int j=0;j<N;j++)
			{
				cin>>input;
				if(input=='A')
				{
					sx=j;
					sy=i;
				}
				else if(input=='B')
				{
					ex=j;
					ey=i;
				}
				else if(input=='Z')
				{
					if(j>1&&i>0)
						trip[i-1][j-2]=-1;
					if(j>1&&i<M-1)
						trip[i+1][j-2]=-1;
					if(j>0&&i>1)
						trip[i-2][j-1]=-1;
					if(j>0&&i<M-2)
						trip[i+2][j-1]=-1;
					if(j<N-2&&i>0)
						trip[i-1][j+2]=-1;
					if(j<N-2&&i<M-1)
						trip[i+1][j+2]=-1;
					if(j<N-1&&i>1)
						trip[i-2][j+1]=-1;
					if(j<N-1&&i<M-2)
						trip[i+2][j+1]=-1;
					trip[i][j]=-1;//�`�N�o��
				} 
			}
		queue<pii> togo;
		togo.emplace(sy,sx);
		trip[sy][sx]=1;
		trip[ey][ex]=0;
		while(!togo.empty())
		{
			int y=togo.front().first,x=togo.front().second,goy,gox;
			//*test*/cout<<x<<y<<' '<<trip[y][x]<<endl;
			if(x==ex&&y==ey)
			{
				cout<<"Minimal possible length of a trip is "<<trip[y][x]-1<<endl;
				break;
			}
			togo.pop();
			for(int i=0;i<8;i++)
			{
				if(i==0)gox=x+1,goy=y+1;//�k�W 
				else if(i==1)gox=x-1,goy=y-1;//���W 
				else if(i==2)gox=x+1,goy=y-1;//�k�W 
				else if(i==3)gox=x-1,goy=y+1;//���U 
				else if(i==4)gox=x+1,goy=y;//�k 
				else if(i==5)gox=x-1,goy=y;//��  
				else if(i==6)gox=x,goy=y+1;//�U 
				else if(i==7)gox=x,goy=y-1;//�W
				if((gox>=0&&gox<N)&&(goy>=0&&goy<M))//�P�_�L�W�X�}�C�d��
				{
					//�p�G�S���Q�O���L(�i�H��) 
					if(!trip[goy][gox]) 
					{
						//*test*/cout<<' '<<gox<<goy<<' '<<trip[goy][gox]<<endl;
						togo.emplace(goy,gox);
						trip[goy][gox]=trip[y][x]+1;
					} 
				} 
			}
		}
		if(togo.empty())
			cout<<"King Peter, you can't go now!"<<endl;
	}
	return 0;
}

