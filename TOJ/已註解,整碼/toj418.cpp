#include<iostream>
using namespace std;

int main()
{
    //�F�A�ڷ��o���D�����캡���گu�O���� 
    long long N,M,P,sum;
    cin>>N>>M>>P;
    cout<<(((N-M)%P*(N%P))%P*(M%P))%P<<endl;
    return 0;
}
