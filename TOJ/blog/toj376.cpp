//����������AC�A�x�s���覡�ק�ˬO�����|AC 
#include<iostream>
using namespace std;

const int mod =1000000009;

//�����O��ƦC���}�C�A�w�]��0(�S�����L)
//�D�n�ت��O�Ψӥ[�ֻ��j�t�סA�p�G�w�g�o����i�����ȡA���j�i�H���έ��ư� 
//���M���j�|�ܱo�A�W�źC!!!! 
long long f[100000000];//�D�حn�D2^63-1�A�S�`�N��...�S��k�}����j.... 

//�D�o�ĴX���O���ƦC�����j�禡
long long F(long long n)
{
    //�w�]1,2����1 
    if(n<=2)
        return f[n]=1;

    //�p�G�w�g�������A�����^�ǸӬ���
    if (f[n])
        return f[n];
        
    long long k = (n%2+n)/2;

    //�N...�Ӱ��a�A�аѾ\����ʬ�>�O��ƦC>�x�}...
    f[n]=(n%2)?(F(k)*F(k)+F(k-1)*F(k-1)):(2*F(k-1)+F(k))*F(k);
    if(f[n]>=mod)f[n]%=mod;
    return f[n];
}

int main() {
    int i;
    while(cin>>i) 
    {
        cout<<F(i+2)-1<<endl;
    }
    return 0;
}
