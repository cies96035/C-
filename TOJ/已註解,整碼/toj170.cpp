#include <iostream>
using namespace std;

//��XN���P�P��(���ǯS�ҭn����)
void coutstartree(int N,int shift)
{
    for(int i=0;i<N;i++)//N�h�P�P�� 
    {
    	for(int j=0;j<shift;j++)//�Y�ǯS�ҭn����P�P��
			cout<<' ';
    	for(int j=i+1;j<N;j++)//�ɬP�P��Ů�
			 cout<<' ';
		for(int j=0;j<2*i+1;j++)//��X�P�P
			cout<<'*';
		cout<<endl; 
	}
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T; 
    cin>>T;
    char c;
	int n; //�ŧic,n�ܼ� 
    while(T--)//��Jc,n,�@T�� 
    {
        cin>>c>>n;
        if(c=='A')
        	coutstartree(n,0);//n�h�P�P�� 
        else if(c=='B')
        {
        	coutstartree(n,0);//��n�h�P�P�� 
        	coutstartree(n,0);
		}
        else if(c=='C')
        	for(int i=1;i<=n;i++)
        		coutstartree(i,n-i);//i�h�P�P��A��i�h����n-i�h 
        else if(c=='D')
        	coutstartree(10*n,0);
        else if(c=='E')
        {
        	coutstartree(n,2);//����2�h
			for(int i=0;i<3+2*n;i++)
				cout<<'#';//�ɬ֮�
			cout<<endl;
		}
        else if(c=='F')
        	coutstartree(2*n,0);
        else if(c=='G')
        	coutstartree(3*n,0);
        else if(c=='H')
        	coutstartree(7*n,0);
        else if(c=='I')
        	coutstartree(4*n-1,0);
        cout<<endl;
    }
    return 0;
}
