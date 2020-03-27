#include<iostream>
using namespace std;

int main()
{
    int N,P;
    cin>>N;
    char K[N],LorR;
    for(int i=0;i<N;i++)
    {
        cin>>K[i];
        if(K[i]=='P')P=i;//¬ö¿ýª±®a¦ì¸m 
    }
    
    cin>>LorR;
    if(LorR=='L')swap(K[P],K[P-1]);
    else swap(K[P],K[P+1]);
    
    for(int i=0;i<N;i++)
		cout<<K[i];
    cout<<endl;
    return 0;
}
