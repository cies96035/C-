#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int V,n;
    while(cin>>V>>n)
    {
        int w[n],p[n],maxvalue[V+1];
        
        //maxvalue������n��i���ɭԡA�̤j���Ȭ��h�֡A�w�]��0 
        memset(maxvalue,0,sizeof(maxvalue));
        
        //��J�C�Ӫ��~����n���� 
        for(int h=0;h<n;h++)
			cin>>w[h]>>p[h];
        
		for(int i=0;i<n;i++)//�C�Ӫ��~�]�@�� 
            for(int j=w[i];j<=V;j++)//�p��Ӫ�����n��������s 
            	if(maxvalue[j-w[i]]+p[i]>maxvalue[j])//�p�G��s���������ȡA��s 
            		maxvalue[j]=maxvalue[j-w[i]]+p[i];
            		
        cout<<maxvalue[V]<<'\n';
    }
    return 0;
}
