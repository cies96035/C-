#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    char k;
    int ans=0;
    bool f=0;//�P�_�O�_�X�{�L�Ʀr 
    while(cin.get(k))
    {
        if(k==' ')
            if(f)//�J��Ů�ɡA�P�_�O�_�X�{�L�Ʀr�A�X�{�L���ܵ��׼W�[ 
                ans++,f=0;
        else if(k=='\n')
        {
            if(f)//�P�Ů�@�ˡA�P�_�O�_�X�{�L�Ʀr 
                ans++,f=0;
            cout<<ans<<'\n';//��X���� 
            ans=0;//�����k�s 
        }
        else
            f=1;//�X�{�L�Ů�M����H�~���N�������Ʀr(���D�u���Ʀr���i��) 
    }
    return 0;
}
