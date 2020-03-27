#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int Case=1,N;//�O���ĴX��case 
	while(cin>>N)
	{
		//���s�ɵ����{��
		if(!N)return 0; 
		
		const int end=N-1;//����`�� 
		int hole[N][N],x=0,y=0,num=1;//N*N�Ӭ},(x,y)���O�O���{�b���쪺�a�I,num�����Ӧa�I���ƭ� 
		
		//�s�y�x�} 
		hole[x][y]=num;//���W�����Ĥ@��
		for(int step=1;num<N*N;step++)
		{
			//���k�@��A�����U�쩳�A���U�@��A���k�W�쩳
			//�p�G1,3�B�X�{���D�A�令���U�M���k 
			switch(step%4)
			{
				case 1://�Ĥ@�B 
					//�p�G�S��k�k���@��A���U�� 
					if(x==end)hole[x][++y]=++num;
					else hole[++x][y]=++num;
					break;
				case 2://���U�쩳
					while(x>0&&y<end)//����I�����䬰��
						hole[--x][++y]=++num;
					break;
				case 3://���U�A�p�G�X���D���k 
					if(y==end)hole[++x][y]=++num;
					else hole[x][++y]=++num;
					break;
				case 0://�k�W�쩳
					while(x<end&&y>0)//����I�����䬰��
						hole[++x][--y]=++num;
					break;
			}
		} 
		
		//��X
		cout<<"Case "<<Case++<<':'<<endl; 
		for(y=0;y<N;y++)
		{
			for(x=0;x<N;x++)
			{
				cout<<setw(3)<<hole[x][y];
			}
			cout<<endl;
		}
	}
	return 0;
}

