#include<iostream>
#include<cstring>
using namespace std;

int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
    //A�x�s�Ӧ�m�쩳���ܰʶq�Asum�x�s�Y��m���ܰʶq
    //max,min�����̤j�̤p�� 
    int A[N+1],sum=0,max=-2e9,min=2e9;
    memset(A,0,sizeof(A));//�@�}�l�ܰʶq���O0 
    //�N�ק諸��m�Τj�p��JA�}�C 
    while(P)
    {
        P--;
        A[L[P]-1]+=V[P];//�N����쩳���ܰʶq+V 
        A[R[P]]-=V[P];//�k��쩳���ܰʶq-V
        //�����k�䪺�ܰʶq+V�A�k��쩳���ܰʶqV-V=0 
    }
    //��ק諸�ȥΨ�H[i]�A�P�ɨ��o�̤j�γ̤p�� 
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
        H[i]+=sum;
        if(H[i]>max)max=H[i];
        if(H[i]<min)min=H[i];
    }
    return max-min;
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
