#include<iostream>
using namespace std;

int main() {
    char a;
    int num,T,ans=0;
    cin>>T;//����� 
    while(T--)
    {
    	for(int i=0;i<3;i++)//�T�Ӹ��X 
    	{
	        cin>>a;
	        ans=ans*26+a-'A';
		}
		cin>>num;//��J�@�ӭt�� 
		ans+=num;
		//�P�_ 
        if(ans<=100&&ans>=-100)cout<<"nice"<<endl;
        else cout<<"not nice"<<endl;
        ans=0;//�k�s 
    }
    return 0;
}
