#include<iostream>
using namespace std;

const int maxNode = 1000000;

//���l�`�I�M�k�l�`�I���y�Ц�m 
#define LC (now*2)
#define RC (now*2+1) 
#define M (L+R)/2

struct Node
{
    int max,flag;
}node[maxNode];

//�سy�@��H[]���u�q��
//now���u�q�ƪ��y��
//L,R�����I���]�tH����m 
//H*��H[] 
void build(int now,int L,int R,int *H)
{
	node[now].flag=0;
    if(L==R)//��u�q��̩��h�ɡA�Ӽh�ƭȬ�H[L]���ƭ� 
    {
        node[now].max=H[L];
        return;
    }
    //�Y�ëD�̩��h�A�غc���U�����k��h�u�q��
	//�@�Ӹ`�I������b
	//���O��L��M(���`�I)�AM+1��R(�k�`�I) 
    build(LC,L,M,H);
    build(RC,M+1,R,H);
    
    //�������`�I���k��l�`�I���̤j�M�̤p�� 
    node[now].max=max(node[LC].max,node[RC].max);
}

//now �ثe�`�I�y��
//L,R�ثe�`�I�]�t���d��
//uL,uR�Q�n��s��ƪ��d��
//add��s����Ƥ��e 
int x,v,K;
void update(int now,int L, int R,int t)
{
    if (L == R)
    {
        if(t==L&&K==1)
        {    
            node[now].max += x;
        }
        else if(t==L)
        {
            node[now].max %= v;
		}
        return;
    }
 
    if (t<=M) update(LC,L,M,t);
    else update(RC,M+1,R,t);
 
    node[now].max=max(node[LC].max,node[RC].max);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N,T;
	cin>>N;
	int H[N];
	for(int i=0;i<N;i++)cin>>H[i];
    build(1,0,N-1,H);
	cin>>T;
	while(T--)
	{
		cin>>K;
		if(K==1)
		{
			int i;
			cin>>x>>i;
			update(1,0,N-1,i);
		}
		else if(K==2)
		{
			int L,R;
			cin>>L>>R>>v;
			for(int i=L;i<=R;i++)
			{
				update(1,0,N-1,i);
			}
		}
		else
		{
			cout<<node[1].max<<'\n';
		}
	}
}
