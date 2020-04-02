#include <iostream>
using namespace std;

#define TenMillion 10000000

//紀錄1~千萬是否為質數，及該質數位置 
int prime[TenMillion+1]={0,0},m=1;

void Eratosthenes()//埃式篩法 
{
	for(int h=2;h<=TenMillion;h++)//2以上全部預設為質數 
    	prime[h]=1;

    for(int i=2;i<=TenMillion;i++)
    {
        if(prime[i])//將所有質數的倍數作為非質數 
        {
        	prime[i]=m;//是質數的話，記錄下來是第幾個質數 
        	m++;//質數數量增加 
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
			cout<<"NO"<<endl;//如果找不到T值，則輸出NO
		else
			cout<<prime[T]<<endl;
    }
    return 0;
}
