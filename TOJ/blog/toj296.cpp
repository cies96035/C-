#include <iostream>
using namespace std;

#define TenMillion 10000000

//����1~�d�U�O�_����� 
bool prime[TenMillion+1]={0,0};
//m�����@���h�֭ӽ�ơAPRIME�Ӷ��ǱM���s����
int PRIME[700000],m=0;

void Eratosthenes()//�J���z�k 
{
	for(int h=2;h<=TenMillion;h++)//2�H�W�����w�]����� 
    	prime[h]=1;

    for(int i=2;i<=TenMillion;i++)
    {
        if(prime[i])//�N�Ҧ���ƪ����Ƨ@���D��� 
        {
        	PRIME[m]=i;//�O��ƪ��ܡA�O���U�� 
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
        /*
        //�ΤG���j�M�k�קKTLE
		//�Υ�lowerbound�]�i�H�A�t�׮t���h 
		bool flag=1;
        int min=0,max=m;
        while(max>=min)                 
        {
            if(PRIME[(min+max)/2]<T)
                min=(min+max)/2+1;
            else if(PRIME[(min+max)/2]>T)
                max=(min+max)/2-1;
            else
            {
                cout<<(min+max)/2+1<<endl;
                flag=0; 
                break;
            } 
        }
        if(flag)cout<<"NO"<<endl;
		*/
		if(*lower_bound(PRIME,PRIME+m,T)!=T)
			cout<<"NO"<<endl;//�p�G�䤣��T�ȡA�h��XNO
		else
			cout<<lower_bound(PRIME,PRIME+m,T)-PRIME+1<<endl;
    }
    return 0;
}
