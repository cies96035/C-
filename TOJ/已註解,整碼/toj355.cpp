#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,K,second=0,biggest=0;
    cin>>N>>K;//�o��K�Τ��� 
    while(N--)
    {
        cin>>K;
        if(K>biggest)swap(K,biggest);
        if(K>second)swap(K,second);
        //�C���j��A�x�s�̤j�M�ĤG�j���� 
    }
    cout<<second<<endl;
    //��X�̫᪺�ĤG�j�� 
    return 0;
}
