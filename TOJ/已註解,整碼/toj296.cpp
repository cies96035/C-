#include <iostream>
using namespace std;

#define TenMillion 10000000

//紀錄1~千萬是否為質數 
bool prime[TenMillion+1]={0,0};
//m紀錄共有多少個質數，PRIME照順序專門存放質數
int PRIME[700000],m=0;

void Eratosthenes()//埃式篩法 
{
	for(int h=2;h<=TenMillion;h++)//2以上全部預設為質數 
    	prime[h]=1;

    for(int i=2;i<=TenMillion;i++)
    {
        if(prime[i])//將所有質數的倍數作為非質數 
        {
        	PRIME[m]=i;//是質數的話，記錄下來 
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
        /*
        //用二分搜尋法避免TLE
		//或用lowerbound也可以，速度差不多 
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
			cout<<"NO"<<endl;//如果找不到T值，則輸出NO
		else
			cout<<lower_bound(PRIME,PRIME+m,T)-PRIME+1<<endl;
    }
    return 0;
}
