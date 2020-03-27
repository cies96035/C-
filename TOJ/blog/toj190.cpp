#include<iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int N;
    cin>>N;
    int k[N];
    for(int i=0;i<N;i++)
        cin>>k[i];
    
    //直到出現第一個left>=right的情況才結束迴圈 
    for(int e=0;e<N;e++)
    {
        int left=0,right=0,l=0,r=0;
        for(int i=e;i>=0;i--,l++)
            left+=k[i]*l;
        for(int i=e;i<N;i++,r++)
            right+=k[i]*r;

        if(left==right)
        {
            cout<<e+1<<endl;
            break;
        }
        if(left>right)
        {
            cout<<e<<' '<<e+1<<endl;
            break;
        }
    }
    return 0;
}
