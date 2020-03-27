#include<iostream>
#include<cstring>
using namespace std;

#define M ((L+R)/2)
#define LC (root*2)
#define RC (root*2+1)
#define Mini -100000
#define Maxi 100000

struct Node{int max,min;}node[40010];
//1~10000窾计,程ノ40000竊翴 
//魁赣竊翴程の程 

//虫翴穝 
int n,k;//穝竚穝 
void update(int root,int L,int R)  
{  
    if(L==R)
    {  
    	if(k==-3)//砞ぃノ猵程程 
    	{
    		node[root].min=Maxi;
    		node[root].max=Mini;
		}
		else
			node[root].max=node[root].min=k;
        return;  
    }   
    if(n<=M) update(LC,L,M);  
    if(n>M) update(RC,M+1,R); 
    node[root].max=max(node[RC].max,node[LC].max);
    node[root].min=min(node[RC].min,node[LC].min);
}  

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
	//魁–计瞷Ω计,魁羆计瞷Ω计(狦⊿狥﹁块玥ぃ块) 
	int num[10001],nums=0;
	memset(num,0,sizeof(num));
    //箇砞–竊翴程/程伐/伐(ぃノ篈 
    for(int i=0;i<40010;i++)
    {
    	node[i].max=Mini;
    	node[i].min=Maxi;
	}
	//酚肈ヘ惠―块 
    while(cin>>n)
    {
        if(n==0)
            break;
        else if(n==-1)
        {
			//讽⊿狥﹁块碞铬筁
        	if(nums)
			{
        		//块场絛瞅程 
	            n=node[1].min;
	            cout<<n<<" ";
	        	num[n]--;//程Ω计ノ奔Ω 
	        	
	        	//讽程Ω计ノЧ,跑Θぃノ 
	        	if(num[n]==0)
	        	{ 
	        		k=-3;
					update(1,1,10000);
				}
				nums--;//羆Ω计ノ奔Ω 
			}
        }
        else if(n==-2)//n==-1эΘ程猵 
        {
			if(nums)
			{ 
	            n=node[1].max;
	            cout<<n<<" ";
	        	num[n]--;
	        	
	        	if(num[n]==0)
				{	
	        		k=-3; 
					update(1,1,10000);
				}
			nums--; 
			}
        }
        else
        {
        	//讽num⊿砆絬琿计癘魁筁(┪砆竚筁)玥癘魁ㄓ 
        	if(num[n]==0)	
			{
        		k=n;
				update(1,1,10000);
			} 
        	num[n]++;//计numΩ计糤Ω
			nums++;//羆计糤 
        }
    }
    cout<<endl;
    return 0;
}
