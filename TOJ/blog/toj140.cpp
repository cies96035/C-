#include<iostream>
using namespace std;

int main() {
    char a;
    int num,T,ans=0;
    cin>>T;//測資數 
    while(T--)
    {
    	for(int i=0;i<3;i++)//三個號碼 
    	{
	        cin>>a;
	        ans=ans*26+a-'A';
		}
		cin>>num;//輸入一個負數 
		ans+=num;
		//判斷 
        if(ans<=100&&ans>=-100)cout<<"nice"<<endl;
        else cout<<"not nice"<<endl;
        ans=0;//歸零 
    }
    return 0;
}
