#include<iostream>
using namespace std;

char def[62];//�x�s�𸭥ѥ~�Ӥ� 

void Init()//�]�w�𸭪�� 
{
	char set='A';
	for(int i=0;i<62;i++)
	{
		def[i]=set;
		if(i<25)
			set++;
		else if(i==25)
			set='z';
		else if(i<51)
			set--;
		else if(i==51)
			set='0';
		else if(i<56)
			set+=2;
		else if(i==56)
			set='1';
		else
			set+=2; 
	} 
}

void coutline(int n,int shift)//��X2n+1�����l+����shift�� 
{
	while(shift--)cout<<' ';
	for(int i=0;i<n;i++)cout<<def[i];
	for(int i=n;i>=0;i--)cout<<def[i];
	cout<<endl;
}

int main() {
	Init();//��l�ƽ�� 
    int N;
	while(cin>>N)
    {
        if(N<0)N=-N;//����� 
        if(N>62)
			cout<<"ERROR!"<<endl;//�X�� 
        else
        {
	        for(int i=0;i<N;i++)
	        {
	        	coutline(i,N-i-1);
	        }
	        for(int i=0;i<N;i++)
	        {
	        	//��X��F 
	            for(int j=1;j<N;j++)cout<<" ";
	            cout<<def[N-1]<<endl;
	        }
        }
    }
    return 0;
}
