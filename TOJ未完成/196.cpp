#include<iostream>
using namespace std;
int main()
{
    //cin�[�t 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    //�ŧi�ܼơAf�}�C�Ҭ�0; 
    int S,W,Q,k,A[100001];
    bool f[200001]={0},s[100001]={0};
        
    //��J�߱����� 
    cin>>S;
    for(int i=0;i<S;i++)
    {
        cin>>k;
        if(s[k])//�p�G�D�ئ��j�q�ۦP�ƭȡA�i���C�B�z�߱����Ƴt�� 
        {
            S--;
            i--;
            continue;
        }
        s[k]=1;
        A[i]=k;
        for(int j=i;j>=0;j--)
            if(!f[k+A[j]])
                f[k+A[j]]=1;
    }

    //�P�_�ÿ�X 
    cin>>Q;
    while(Q--)
    {
        cin>>W;
        if(f[W])cout<<"yes\n";
        else cout<<"no\n";
    }
        
    
    return 0;
}
