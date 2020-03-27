#include <iostream>
using namespace std;

#define TenMillion 10000000

//����1~�d�U�O�_����ơA�θӽ�Ʀ�m 
int prime[TenMillion+1]={0,0},m=1;

void Eratosthenes()//�J���z�k 
{
	for(int h=2;h<=TenMillion;h++)//2�H�W�����w�]����� 
    	prime[h]=1;

    for(int i=2;i<=TenMillion;i++)
    {
        if(prime[i])//�N�Ҧ���ƪ����Ƨ@���D��� 
        {
        	prime[i]=m;//�O��ƪ��ܡA�O���U�ӬO�ĴX�ӽ�� 
        	m++;//��Ƽƶq�W�[ 
            for(int j=i,k=2;j*k<=TenMillion;k++)
            {
            	if(prime[j*k])
            		prime[j*k]=0;
            } 
		}
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T;
    
	Eratosthenes();
	
    while(cin>>T)
    {
		if(!prime[T])
			cout<<"NO"<<endl;//�p�G�䤣��T�ȡA�h��XNO
		else
			cout<<prime[T]<<endl;
    }
    return 0;
}
