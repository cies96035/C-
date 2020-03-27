#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    while((a%=b)&&(b%=a));
    return a+b;
}

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    char k;
    //單一分子,單一分母,分子積,分母積 
    int kid=0,mom=0,kidsum=1,momsum=1;
    bool flag=1,flag2=0;
	//flag打開代表紀錄分子，關起來則記錄分母 
	//flag2判斷是否要把分子乘進總積裡，避免多個空格的狀況出錯 
    while(cin.get(k))
    {
        if(k>='0'&&k<='9'&&flag)//分子 
        {
            kid=kid*10+k-'0';
            flag2=1;
        }
        else if(k>='0'&&k<='9')//分母 
        {
            mom=mom*10+k-'0';
            flag2=1;
        }
        if(k=='/')
        {
            flag=0;
        }
        if((k==' '||k=='\n')&&flag2)
        {
            kidsum*=kid;
            if(mom!=0)//如果mom沒記錄到(也就是非分數，則不用紀錄 
                momsum*=mom;
            kid=mom=0;//歸零 
            flag2=0;
            flag=1;
        }
        if(k=='\n')
        {
        	//約分 
            int GCD=gcd(kidsum,momsum);
            kidsum=kidsum/GCD;
            momsum=momsum/GCD;
            if(momsum!=1)//如果分母為1則不用輸出分母 
                cout<<kidsum<<'/'<<momsum<<endl;
            else
                cout<<kidsum<<endl;
            kidsum=momsum=1;//還原 
        }
    }
    return 0;
}

