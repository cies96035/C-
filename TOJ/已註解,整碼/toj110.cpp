#include<iostream>
using namespace std;

void coutline(int N,int shift)
{
	while(shift--)cout<<' ';
	for(int i=2*N+1;i>0;i--)cout<<'*';
	cout<<endl;
}

int main()
{
    int h,n;
    cin>>n;
	while(n--)
    {
        cin>>h;
        h-=3;
        
        for(int i=0,shift=h+2;i<h;i++,shift--)//上方部分 
            coutline(i,shift);
        
        //中間部分
		coutline(h+2,0);
		coutline(h+1,1);
		coutline(h+2,0);
        
        for(int i=h-1,shift=3;i>=0;i--,shift++)//下方部分 
            coutline(i,shift);
    }
    return 0;
}
