#include <iostream>
using namespace std;

int main() {
    
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)//����X��(����) 
    {
    	for(int j=i;j<N;j++)//�ɪŮ�A��n�Ƹ�N-n�ӪŮ� 
			cout<<' ';
		for(int j=0;j<2*i-1;j++)//��n�ƿ�X2n-1���P�P 
			cout<<'*';
		cout<<endl;
    }
    return 0;
}

