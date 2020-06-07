//¤@©w¦³¿ù
#include <iostream>
using namespace std;

int main() {
    int N,score[2]={0,0};
    cin>>N;
    int a[N],start=0,end=N-1;
    for(int i=0;i<N;i++)
        cin>>a[i];
    for(int i=0;i<N-1;i++)
    {
    	int s=start,e=end,
		chooses=a[s]-max(a[s+1],a[e]),
        choosee=a[e]-max(a[s],a[e-1]);
        if(chooses>choosee)
        {
            score[i%2]+=a[start];
            start++;            
        }
        else if(chooses<choosee) 
        {
            score[i%2]+=a[end];
            end--;            
        }
        else
        {
        	chooses=max(a[s+1]-max(a[s+2],a[e]),a[e]-max(a[s+1],a[e-1]));
        	choosee=max(a[s]-max(a[s+1],a[e-1]),a[e-1]-max(a[s],a[e-2]));
        	if(chooses<choosee)
        	{
	            score[i%2]+=a[start];
	            start++;            
        	}
        	else
        	{
	            score[i%2]+=a[end];
	            end--;            
        	}
		}
    }
    score[(N-1)%2]+=a[start];
    cout<<score[0]<<' '<<score[1]<<endl;
    
    
    return 0;
}
