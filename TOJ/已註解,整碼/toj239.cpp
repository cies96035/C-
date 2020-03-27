#include<iostream>
#include<cstring>
using namespace std;

int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
    //A儲存該位置到底的變動量，sum儲存某位置的變動量
    //max,min紀錄最大最小值 
    int A[N+1],sum=0,max=-2e9,min=2e9;
    memset(A,0,sizeof(A));//一開始變動量都是0 
    //將修改的位置及大小放入A陣列 
    while(P)
    {
        P--;
        A[L[P]-1]+=V[P];//將左邊到底的變動量+V 
        A[R[P]]-=V[P];//右邊到底的變動量-V
        //左邊到右邊的變動量+V，右邊到底的變動量V-V=0 
    }
    //把修改的值用到H[i]，同時取得最大及最小值 
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
