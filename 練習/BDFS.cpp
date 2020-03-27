#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//�i�ۦ��queue�令queue�[��A�򥻤W�N��BFS�ܦ�DFS�F 

#define N 6 //6���I 

int main()
{
	//�HTOJ9�Ĥ@�����ꬰ�d��:(0,5)(0,1)(5,4)(2,3)(3,0)(4,1)(1,2)
	//�������V��:link[a][b]=1�ɥN��a��b�O�q��
	bool link[N][N]=
	{{0,1,0,1,0,1},
	{1,0,1,0,1,0},
	{0,1,0,1,0,0},
	{1,0,1,0,0,0},
	{0,1,0,0,0,1},
	{1,0,0,0,1,0}};
	//�����C���I�O�_���L(�קK�@�����ƨ��|�L���j��TLE 
	bool visited[N]={0,0,0,0,0,0};
	//�����ǳƭn�e������C
	queue<int> togo,ctogo;
	
	togo.push(4);//�ǳƱq��4�I�}�l�X�o
	visited[4]=1;//��4�I�w�Q�j�M�L
	
	cout<<"***���ɫݫe���M��:"<<togo.front()<<endl<<endl;
	
	while(!togo.empty())//����S���a��i�H�e������ 
	{
		int now=togo.front();
		togo.pop();
		
		cout<<"�{�b�n�M��P�I"<<now<<"�۾F���I"<<endl<<endl; 
		
		//��Ҧ���{�b�o�I�۳s������i�ǳƫe������C 
		for(int i=0;i<N;i++)
			if(link[now][i])
			{
				if(visited[i])
				{
					cout<<i<<"�w�Q�j�M�L�A����i��C"<<endl; 
					//��i��C���ܷ|�y�����I���Ʒj�M�Ӳ��Ϳ��~ 
				}
				else
				{
					cout<<i<<"��i��C,"<<i<<"�w�Q�j�M"<<endl; 
					togo.push(i);
					visited[i]=1;
				}
			} 
		cout<<endl<<"***���ɫݫe���M��:";
		ctogo=togo;
		while(!ctogo.empty())
		{
			cout<<ctogo.front()<<' ';
			ctogo.pop();
		}
		cout<<endl<<endl;
	} 
	cout<<"�M�欰�šA�����j���A���}�j��"<<endl;
	//�@���D�ط|�]�m�@�ӵ�������A�p�G�F���N����break���X�j��
	//���U�Y��������O��F�̧C�I�A�p�G�S���F��break����N�O�L�k��F�̧C�I 
	
	return 0;
}

