#include<iostream>
#include<cstring>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size())swap(a,b);//預設為b較長的狀況 
    int flag=0,f,k=b.size()-a.size(),bs=b.size(),as=a.size();
    //flag:主要避免輸出前導零 
    
    for(int h=0;h<k;h++)//b比a高位的部分直接輸出就好(任何數^0=任何數) 
        cout<<b[h];
    if(k!=0)flag=1;//因為b輸出過了，所以之後的零都要輸出 
    
    
    for(int h=0;h<as;h++,k++)
    {
        if(a[h]<='9'&&a[h]>='0')
        {
            if(b[k]<='9'&&b[k]>='0')
            	f=(a[h]-'0')^(b[k]-'0');//數字^數字 
            else
            	f=(a[h]-'0')^(b[k]-'A'+10);//數字^字母 
        }
        else
        {
            if(b[k]<='9'&&b[k]>='0')
            	f=(a[h]-'A'+10)^(b[k]-'0');//字母^數字 
            else
            	f=(a[h]-'A'+10)^(b[k]-'A'+10);//數字^數字 
        }
        
        //輸出 
        if(flag||f!=0)//直到出現第一個非零以外的數為止都不輸出(不輸出前導零) 
        {
            if(f<=9)
            	cout<<f;//如果f為數字，直接輸出 
            else
            	cout<<(char)(f+'A'-10);//否則轉換成字母
			if(!flag)//出現首次非零以外的數，之後都可以直接輸出
            	flag=1; 
        }   
    }
    if(!flag)cout<<0;//如果從來沒有輸出過，則輸出0 
	cout<<endl;//最後換行 
    
    return 0;
}
