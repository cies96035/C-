#include<iostream>
using namespace std;

char def[62];//儲存樹葉由外而內 

void Init()//設定樹葉初值 
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

void coutline(int n,int shift)//輸出2n+1片葉子+移位shift格 
{
	while(shift--)cout<<' ';
	for(int i=0;i<n;i++)cout<<def[i];
	for(int i=n;i>=0;i--)cout<<def[i];
	cout<<endl;
}

int main() {
	Init();//初始化賦值 
    int N;
	while(cin>>N)
    {
        if(N<0)N=-N;//絕對值 
        if(N>62)
			cout<<"ERROR!"<<endl;//出錯 
        else
        {
	        for(int i=0;i<N;i++)
	        {
	        	coutline(i,N-i-1);
	        }
	        for(int i=0;i<N;i++)
	        {
	        	//輸出樹幹 
	            for(int j=1;j<N;j++)cout<<" ";
	            cout<<def[N-1]<<endl;
	        }
        }
    }
    return 0;
}
