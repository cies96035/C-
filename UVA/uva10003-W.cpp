#include<iostream>
#include<vector>
using namespace std;

int c[100];
struct LIST
{
    LIST()
    {
        next=NULL;
        v=0;
    }
    LIST* next;
    int v;
};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int l,n;
    while(cin>>l && l!=0 && cin>>n)
    {
        LIST Head;
        LIST *now;
        Head.next=now=new LIST;
        c[0]=0;
        for(int i=1; i<=n; i++)
        {
            cin>>c[i];
            now->v=c[i]-c[i-1];
            now->next=new LIST;
            now=now->next;
        }
        now->v=l-c[n];
        int sum = 0;
        while(Head.next->next!=NULL)//more than two
        {
            now=Head.next;
            int Min=2e9;
            LIST *MinP;
            while(now->next!=NULL)
            {
                int k=now->v+now->next->v;
                //cout<<now->v<<','<<now->next->v<<':'<<k<<' ';
                if(Min>k)
                {
                    Min=k;
                    MinP=now;
                }
                now=now->next;
            }
            //cout<<endl;
            //cout<<Min<<endl;
            sum+=Min;
            MinP->v=Min;
            MinP->next=MinP->next->next;
        }
        cout<<"The minimum cutting is "<<sum<<".\n";
        
    }
    return 0;
}