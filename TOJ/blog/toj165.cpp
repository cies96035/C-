#include<iostream>
using namespace std;

#define n 100001

int division[n];//�C�ӤH������ 

//��l�ơA�C�ӤH�ۤv�@�� 
inline void Init(int k)
{
	for(int i=0;i<k;i++)
		division[i]=i;
}

//�M��a���էO 
inline int find (int a)
{
	return division[a]==a ? a : division[a]=find(division[a]);
	/*
	�o�ˤ]�i�H�A���ۤ�W���j�q����ɷ|���C 
	return division[a]==a ? a : find(division[a]);
	*/
}

//�Na,b��H���էO�X�֬�b�էO 
inline void Union (int a,int b)
{
	//���αN�����P���骺���אּb���էO�A
	//�u�n����a�էO���Y�Y��m�N�n�A�����find�N�|��� 
	division[find(a)]=find(b);
}

//�P�_��ӤH���էO�O�_�@�� 
inline bool same (int a,int b){
	return find(a)==find(b);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
    cin>>T;
    while(T--)
    {
        int N,M; 
        cin>>N>>M;
        Init(N+1);//��l�� 
        
		while(M--)
        {
            int a,b;
            cin>>a>>b;
            //�Nb�էO���H����a�� 
            Union(b,a);
        }
        
        for(int i=1;i<=N;i++)
			cout<<find(division[i])<<'\n';
    }
	return 0;
}

