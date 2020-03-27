#include<iostream>
using namespace std;
int main()
{
    int A,L;
    cin>>A>>L;
    L*=L;//最初的截面積 
    for(int day=0;true;day++)
    {
        if(L<=A)//當截面積<=A，輸出第幾天並結束 
        {
            cout<<day<<endl;
            return 0;
        }
        L/=2;//每天砍掉一半 
    }
    return 0;
}
