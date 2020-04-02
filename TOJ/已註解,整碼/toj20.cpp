#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	//如果其中一個為0，避免RE所以傳回1 
	if(!a||!b)return 1;
	while((a%=b)&&(b%=a));
    return a+b;
}

int abs(int x)
{
	if(x<0)return -x;
	return x;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    //x,y:儲存x,y的變化量 
    int x,y,x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2)
    {
        x=abs(x2-x1);
        y=abs(y2-y1);
        cout<<x+y+gcd(x,y)<<endl;
    }
    return 0;
}
