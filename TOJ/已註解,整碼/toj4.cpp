#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset> 

//bitset:�x�s1,0�A.to_ulong()�i�H�ഫ��ull; 
//�ɤO�լݬ� 
using namespace std;

typedef unsigned long long ull;

int T,N,L,MinAns;
ull two_pow[63]={1};//return pow(2,i);

void two_pow_Init()//�ت� 
{
    for(int i=0;i<62;i++)
        two_pow[i+1]=two_pow[i]*2;
    return;
}

inline bool cmp(ull x,ull y,int pos)
{
    return (x-x%two_pow[pos+1])!=(y-y%two_pow[pos+1]);
}

void c(ull x[],ull device[],int i,int a)
{    
    ull plug[N];
    memcpy(plug,x,sizeof(plug));
    
    int pos=L-i-1;//�{�b����m 
    
    //�p�G��̫�@�Ӧ줸�A�A�ˬd�@���A�p�G�٬O�@�ˡA��s���� 
    if(i==L)
    {
        for(int j=0;j<N;j++)
            if(plug[j]!=device[j])return;
        MinAns=min(MinAns,a);
        return;
    }
    
    //�{�b��m��plug�t0/1�A�H��device�t0���ƶq 
    int p_zero=0,d_zero=0,p_one;
    for(int j=0;j<N;j++)
    {
        if((plug[j]/two_pow[pos])%2==0)p_zero++;
        if((device[j]/two_pow[pos])%2==0)d_zero++; 
    }
    p_one=N-p_zero;
    
    //�p�Gdevice�s���ƶq���Pplug�s���ƶq->�ˬd���줸�H�e����m�O�_���۵�
	//�O->�i�J�U�@�Ӧ줸�A���i�����ʧ@ 
    if(d_zero==p_zero)
    {
        int j=-1;
        while(++j<N)
            if(cmp(plug[j],device[j],pos))break;
        if(j==N)
            c(plug,device,i+1,a);
    }
    
    //�p�Gdevice�s���ƶq���Pplug�@���ƶq->�i������A�ˬd���줸�e����m�O�_���۵�
	//�p�G�۵��A�h����ʧ@�[�@ �A�i�J�U�@�Ӧ줸 
    if(d_zero==p_one)
    {
    	//1.���� 
        for(int j=0;j<N;j++)((plug[j]/two_pow[pos])%2==0 ? plug[j]+=two_pow[pos] : plug[j]-=two_pow[pos] );
        //2.�Ƨ� 
		sort(plug,plug+N);
		//3.�ˬd 
        for(int j=0;j<N;j++)
            if(cmp(plug[j],device[j],pos))return;
        c(plug,device,i+1,a+1);
    }
    
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    two_pow_Init();
    
    cin>>T;
    
    for(int Case=0;Case<T;)
    {
        MinAns=100;//�����̤p�ȡA�p�G���Q��s->Impossible 
        cin>>N>>L;
        bitset<64> input;
        ull plug[N],device[N];
        
        for(int i=0;i<N;i++)
        {
            cin>>input;
            plug[i]=input.to_ulong();
        }
        
        for(int i=0;i<N;i++)
        {
            cin>>input;
            device[i]=input.to_ulong();
        }
        
		//�ƧǥH�Q�ˬd 
        sort(plug,plug+N);
        sort(device,device+N);
        c(plug,device,0,0);
        
        cout<<"Case #"<<++Case<<": ";
        (MinAns!=100 ? cout<<MinAns<<'\n' : cout<<"IMPOSSIBLE\n");
    }
    return 0;
}
