#include<iostream>
using namespace std;

#define N 1000000007

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    char k;
    //num:記錄每一個數字,sum:紀錄每個數字總和 
    int num=0,sum=0,son;//son:紀錄分子 
    bool flag=0;//判斷是不是分數 
    while(cin.get(k))
    {
        if(k>='0'&&k<='9')
        {
            num=num*10+k-'0';
        }
        else if(k==' ')
        {
            if(!flag)//如果不是分數 
                sum+=num;
            else if(num&&son%num==0)//如果是分數且為整數 
                sum+=son/num,flag=0,son=0;
            num=0;
            sum%=N;
            flag=0;
        } 
        else if(k=='\n')
        {
            if(!flag)//如果不是分數 
                sum+=num;
            else if(num&&son%num==0)//如果是分數且為整數 
                sum+=son/num,son=0;
            cout<<sum%N<<endl;
            sum=num=0;
            flag=0;
        }
        else// 除號 
        {
            son=num;//分子 
            num=0;//數字歸零 
            flag=1;//代表有分數 
        }
    }
    return 0;
}
