/*
��set�����F��
��F��ɤ@�ߥ�find()�Dset[]..
�b�d����= = 
*/
#include<iostream>
#include<cstring> 
using namespace std;

typedef long long ll;
const int maxnum=1000001;
const int smaxnum=1001;

int prime[maxnum],set[maxnum];
bool check[maxnum],used[maxnum];//check[]�����n�ˬd���I�Aused�����O�_�p��Lor���I�D�H�O�_�ˬd�L

void Init(){for(int i=0;i<maxnum;i++)set[i]=i;}//��l�� 
int find(int x){return (set[x]==x ? x : set[x]=find(set[x]));}//��ؼЪ��D�H(? 
void Union(int x,int y){set[find(x)]=find(y);}//�X�� 

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    //�ت�&��l�� 
    Init();
    for(int i=2;i<maxnum;i+=2)prime[i]=2;
    for(int i=3;i<maxnum;i+=2)
        if(!prime[i])
        {
            prime[i]=i;
            if(i<smaxnum)
                for(int j=i*i,k=i+i;j<maxnum;j+=k)
                    if(!prime[j])
                        prime[j]=i;
        }
        
    int N,ans=0,num,record;
    cin>>N;
    while(N--)
    {
        cin>>num;
        if(num==1)ans++;//�S�P�A�C��1�W�߳s�q�� 
        if(!used[num])//�קK���ƭp��A�[�t? 
	    {
		    while(prime[num])//prime[1]=0�A����num��1 
	        {
	            record=prime[num];
	            if(!check[record])check[record]=1;//�X�{�L����Ƴ��ncheck 
	            while(!(num%record))
	                num/=record;
	            if(num>1)
	                Union(prime[num],record);//��P�Ӽƪ���ƦX�ְ_�� 
	        }
	        used[num]=1;
    	}
    }
    memset(used,0,sizeof(used));
    for(int i=0;i<maxnum;i++)
        if(check[i]&&!used[find(i)])
        {
            used[find(i)]=1;//�ӥD�H�w�g�Q��L�F�A����A�p�� 
            ans++;
        }
    
    cout<<ans<<'\n';
    return 0;
}
