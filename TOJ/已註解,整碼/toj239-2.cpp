#include<iostream>
using namespace std;

const int maxNode = 4000000;

//���l�`�I�M�k�l�`�I���y�Ц�m 
#define LC (now*2)
#define RC (now*2+1) 
#define M (L+R)/2

struct Node
{
    int max,min,flag;
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
        node[now].max=node[now].min=H[L];
        return;
    }
    //�Y�ëD�̩��h�A�غc���U�����k��h�u�q��
	//�@�Ӹ`�I������b
	//���O��L��M(���`�I)�AM+1��R(�k�`�I) 
    build(LC,L,M,H);
    build(RC,M+1,R,H);
    
    //�������`�I���k��l�`�I���̤j�M�̤p�� 
    node[now].max=max(node[LC].max,node[RC].max);
    node[now].min=min(node[LC].min,node[RC].min);
}

//�ݲz�� 
void pushdown(int now)
{
	if(node[now].flag)
	{
		long long k=node[now].flag;
		node[LC].flag+=k;
		node[RC].flag+=k;
		node[LC].max+=k;
		node[LC].min+=k;
		node[RC].max+=k;
		node[RC].min+=k;
		node[now].flag=0;
	}
}

//now �ثe�`�I�y��
//L,R�ثe�`�I�]�t���d��
//uL,uR�Q�n��s��ƪ��d��
//add��s����Ƥ��e 
int add;
void update(int now,int L, int R,int uL,int uR)
{
	if(uL>R||uR<L)return ;
	if(uL<=L&&uR>=R)
	{
		node[now].flag+=add;
		node[now].max+=add;
		node[now].min+=add;
		return;
	}
	pushdown(now);
		
    update(LC,L,M,uL,uR);
   	update(RC,M+1,R,uL,uR);
 
    node[now].max=max(node[LC].max,node[RC].max);
    node[now].min=min(node[LC].min,node[RC].min);
}

int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
    build(1,0,N-1,H);
    for(int i=0;i<P;i++)
    {
    	add=V[i];
        update(1,0,N-1,L[i]-1,R[i]-1);
    }
    return node[1].max-node[1].min;
}
/*int main()
{
	const int maxN = 1000000;
	const int maxP = 1000000;
    int *H = new int[maxN];
    int *L = new int[maxP];
    int *R = new int[maxP];
    int *V = new int[maxP];
    int N,P;
    while( cin>>N>>P )
    {
        for(int i=0;i<N;++i)
            cin>>H[i];
        for(int i=0;i<P;++i)
            cin>>L[i]>>R[i]>>V[i];
        cout<<Answer(N,P,H,L,R,V)<<endl;
    }
}*/
