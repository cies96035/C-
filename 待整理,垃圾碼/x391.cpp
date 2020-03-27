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

int x,v,K;
//�ݲz�� 
void pushdown(int now)
{
	if(node[now].flag)
	{    
	int k=node[now].flag;
		if(K==1)
		{
		    node[LC].flag=node[RC].flag=k;
		    node[LC].max+=k;
		    node[RC].max+=k;
		}
		else
		{
		    node[LC].flag=node[RC].flag=k;
		    node[LC].max%=k;
		    node[RC].max%=k;
		}
		node[now].flag=0;
	}
}

//now �ثe�`�I�y��
//L,R�ثe�`�I�]�t���d��
//uL,uR�Q�n��s��ƪ��d��
//add��s����Ƥ��e 
void update(int now,int L, int R,int uL,int uR)
{
	
	/*cout<<"   "<<node[1].max<<'\n'
	<<" "<<node[2].max<<"   "<<node[3].max<<'\n'
	<<node[4].max<<' '<<node[5].max<<' '<<node[6].max<<' '<<node[7].max<<'\n';
	cout<<"   "<<node[1].flag<<'\n'
	<<" "<<node[2].flag<<"   "<<node[3].flag<<'\n'
	<<node[4].flag<<' '<<node[5].flag<<' '<<node[6].flag<<' '<<node[7].flag<<"\n\n";
	*/
    if(uL>R||uR<L)return ;
    if(uL<=L&&uR>=R)
    {
        if(K==1)
        {
            node[now].flag=x;
            node[now].max+=x;
        }
        else
        {
            node[now].flag=v;
            node[now].max=max(node[LC].max%v,node[RC].max%v);
        }
        return;
    }
    pushdown(now);
        
    update(LC,L,M,uL,uR);
    update(RC,M+1,R,uL,uR);
 
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
            update(1,0,N-1,i,i);
        }
        else if(K==2)
        {
            int L,R;
            cin>>L>>R>>v;
            update(1,0,N-1,L,R);
        }
        else
        {	
		    cout<<node[1].max<<'\n';
        }
    }
}
