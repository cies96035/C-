#include<iostream>
using namespace std;

/*

     
*/

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T,N,A[10]={0,0,0,0,0,0,0,0,0,0},num;
    cin>>T;
    while(T--)
    {
    	int h=1;
        cin>>N;
        for(;h<=N;h++)
        {
            num=h;
            while(num)
            {
                A[num%10]++;
                num/=10;
            }
        }
        for(int h=0;h<9;h++)
            cout<<A[h]<<" ";
        cout<<A[9]<<endl;
        A[0]=A[1]=A[2]=A[3]=A[4]=A[5]=A[6]=A[7]=A[8]=A[9]=0;
    }
    return 0;
}
