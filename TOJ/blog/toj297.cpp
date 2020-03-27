#include<iostream>
#include<cstring>
using namespace std;

#define M ((L+R)/2)
#define LC (root*2)
#define RC (root*2+1)
#define Mini -100000
#define Maxi 100000

struct Node{int max,min;}node[40010];
//1~10000�@�@�U�ӼƦr,�̦h�Ψ�40000�Ӹ`�I 
//�����Ӹ`�I�̤j�γ̤p�� 

//���I��s 
int n,k;//��s��m�A��s���� 
void update(int root,int L,int R)  
{  
    if(L==R)
    {  
    	if(k==-3)//�]������Ϊ����p�A�̤p�ȫܤj�A�̤j�ȫܤp 
    	{
    		node[root].min=Maxi;
    		node[root].max=Mini;
		}
		else
			node[root].max=node[root].min=k;
        return;  
    }   
    if(n<=M) update(LC,L,M);  
    if(n>M) update(RC,M+1,R); 
    node[root].max=max(node[RC].max,node[LC].max);
    node[root].min=min(node[RC].min,node[LC].min);
}  

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
	//�����C�ӼƦr�X�{����,�����`�Ʀr�X�{����(�p�G�S�F���X�h�����X) 
	int num[10001],nums=0;
	memset(num,0,sizeof(num));
    //�w�]�C�Ӹ`�I���̤j/�̤p�Ȭ����p/���j(����Ϊ��A 
    for(int i=0;i<40010;i++)
    {
    	node[i].max=Mini;
    	node[i].min=Maxi;
	}
	//���D�ػݨD��X 
    while(cin>>n)
    {
        if(n==0)
            break;
        else if(n==-1)
        {
			//��S�F���X�ɴN���L
        	if(nums)
			{
        		//��X�����d�򪺳̤p�� 
	            n=node[1].min;
	            cout<<n<<" ";
	        	num[n]--;//�̤p�Ȧ��ƥα��@�� 
	        	
	        	//��̤p�Ȫ����ƥΧ���,�ܦ������ 
	        	if(num[n]==0)
	        	{ 
	        		k=-3;
					update(1,1,10000);
				}
				nums--;//�`���ƥα��@�� 
			}
        }
        else if(n==-2)//�Pn==-1�A�令�̤j�Ȫ��p 
        {
			if(nums)
			{ 
	            n=node[1].max;
	            cout<<n<<" ";
	        	num[n]--;
	        	
	        	if(num[n]==0)
				{	
	        		k=-3; 
					update(1,1,10000);
				}
			nums--; 
			}
        }
        else
        {
        	//��num�S�Q�u�q�ưO���L(�γQ���m�L)�A�h�O���U�� 
        	if(num[n]==0)	
			{
        		k=n;
				update(1,1,10000);
			} 
        	num[n]++;//�Ʀrnum���ƼW�[�@��
			nums++;//�`�Ʀr�W�[ 
        }
    }
    cout<<endl;
    return 0;
}
