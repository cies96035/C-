#include<iostream>
using namespace std;

/*
�w�B�zO(n) �C���߰�O(logn)
�ۤ񪽱��C���߰ݱ��L�@��O(n)�n�o�h
�Ĥ@���ݨ�N�����g�u�q�� 
�u�O��ӷQ�Q�o�D�٦���֥B��n�g����k... 
*/
//�򥻤W�N�O�ܰ򥻪��u�q��A�]�S����s�A�u�n�ؾ�j�M�N�n 

#define LC(root) root*2 //���l�`�I 
#define RC(root) root*2+1 //�k�l�`�I 


int state[4000000];
/*
�������A��:
0���Ϭq�Ҭ�0,
1���Ϭq�Ҭ�1,
2���Ϭq�V��0�M1 
*/ 
//�̦h��n*4�ӰϬq�A�̤�n*2-1�A�D�ت��׳̪�1000000

string zero_and_one;
//�ΨӰO��01�ǦC 

//�ؾ�A�𪺤��e�O�P�_�ǦC�C�@�Ӱ϶������A(�Ҭ�0,�Ҭ�1,�V�{) 
void build(int root,int L,int R)
{
	//�̩��h�ɲפ�j�A�϶�L==R�����Ӹ`�I�A�ǦC���e�u���@��(�N�O��L��) 
	if(L==R)
	{
		state[root]=zero_and_one[L]-'0';
		return;
	}
	
	//�������U���j�A���϶��M�k�϶� 
	int M=(L+R)/2;
	build(LC(root),L,M);
	build(RC(root),M+1,R);
	
	//���j����A�P�_���϶������A�ݩ����
	//���϶��k�϶����O1��0���ܡA�N�N���϶����A�O1��0�A��L���p���ܴN�O�V�����A��2 
	state[root]=(state[LC(root)]==state[RC(root)]?state[LC(root)]:2);
	return;
}

int l,r,state_in_query;
//�j�M�ɡA�ΨӰO�����j�M������ɡA�k���
//�٦������o�ӽd�򪺪��A(-1�N���O���L) 

//�j�M�u�q�� 
void query(int root,int L,int R)
{
	//�p�G���`�I�Ϭq�����b�j�M�d��
	//�h�[�J�P�_
	if(l<=L&&r>=R)
	{
		//�p�G���O���L�A�����w�@�Ӫ�l�� 
		if(state_in_query==-1)state_in_query=state[root];
		//�p�G�j�M���G�X�{���@�˪��ȡA�h�O�����V�����A 
		else state_in_query=(state[root]==state_in_query?state_in_query:2);
		return;
	}
	if(state_in_query!=2)//�i�H���[�A�D�n�b�[�t�ΡA�p�G�w�g�X�{�V�������G�A�i�H���ΦA�~��j�M�F 
	{
		int M=(L+R)/2; 
		if(l<=M)query(LC(root),L,M);
		if(r>M)query(RC(root),M+1,R);	
	}
}

int main()
{
	//io�u�� 
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int Case=1;//�����ĴX������ 
	while(cin>>zero_and_one)//�h������ 
	{
		cout<<"Case "<<Case++<<":\n";
		int ZAOend=zero_and_one.size()-1,Q;
		
		//root�T�w�O1
		//�ؾ𪺽d��O��Ӧr��A�]�N�O0~�r�ꪺ���� 
		build(1,0,ZAOend);
		
		//�j�M���� 
		cin>>Q;
		while(Q--)
		{
			//�j�M����ɡB�k��� 
			cin>>l>>r;
			//�`�N���i�४>�k 
			if(l>r)swap(l,r);
			//�j�M���A�]�����O���L 
			state_in_query=-1;
			//�@�ˡA�j�M��root�T�w�O1,�j�M���d��O��ӧǦC 
			query(1,0,ZAOend);
			
			//�P�_���A�A��X���G 
			if(state_in_query==2)cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}

