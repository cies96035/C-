#include<iostream>
using namespace std;

//TLE危機
 
const int maxN=500010;
int floor1[maxN],floor2[maxN],N;
//floor1(i)=k第i層是k樓
//floor2(i)=k第i樓在k層 

void Init()
{
    int i=maxN;
    while(i--)
        floor1[i]=floor2[i]=i;
    return;
}
void testfloor()
{
    for(int i=1;i<=N;i++)
        cout<<floor1[i]<<' ';
    cout<<endl;
    for(int i=1;i<=N;i++)
        cout<<floor2[i]<<' ';
    return;
}

int main()
{
    Init();
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int Q,t,a,b;
    cin>>N>>Q;
    while(Q--)
    {
        cin>>t>>a>>b;
        if(t==1)
        {
            swap(floor1[a],floor1[b]);
            swap(floor2[floor1[b]],floor2[floor1[a]]);
            /*floor2[floor1[b]]=b;
            floor2[floor1[a]]=a;*/
        }
        else
        {
            int cnt=0;
            if(a>b)swap(a,b);
            for(int i=a;i<=b;i++)
            {
                int A=floor1[i],B=floor2[i];
                if(floor1[i]!=i)
                {
                    swap(floor1[i],floor1[B]);
                    swap(floor2[i],floor2[floor1[B]]);
                    /*floor2[i]=i;
                    floor2[floor1[B]]=B;*/
                    cnt++;
                }
            }
            //testfloor();
            cout<<cnt<<'\n';
        }
    }
    return 0;
}
