#include<iostream>
#include<cstring>
using namespace std;

#define M ((L+R)/2)
#define LC (root*2)
#define RC (root*2+1)
#define Mini -100000
#define Maxi 100000

struct Node{int max,min;}node[40010];
//1~10000共一萬個數字,最多用到40000個節點 
//紀錄該節點最大及最小值 

//單點更新 
int n,k;//更新位置，更新的值 
void update(int root,int L,int R)  
{  
    if(L==R)
    {  
    	if(k==-3)//設為不能用的狀況，最小值很大，最大值很小 
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
    
	//紀錄每個數字出現次數,紀錄總數字出現次數(如果沒東西輸出則不能輸出) 
	int num[10001],nums=0;
	memset(num,0,sizeof(num));
    //預設每個節點的最大/最小值為極小/極大(不能用狀態 
    for(int i=0;i<40010;i++)
    {
    	node[i].max=Mini;
    	node[i].min=Maxi;
	}
	//照題目需求輸出 
    while(cin>>n)
    {
        if(n==0)
            break;
        else if(n==-1)
        {
			//當沒東西輸出時就跳過
        	if(nums)
			{
        		//輸出全部範圍的最小值 
	            n=node[1].min;
	            cout<<n<<" ";
	        	num[n]--;//最小值次數用掉一次 
	        	
	        	//當最小值的次數用完時,變成不能用 
	        	if(num[n]==0)
	        	{ 
	        		k=-3;
					update(1,1,10000);
				}
				nums--;//總次數用掉一次 
			}
        }
        else if(n==-2)//同n==-1，改成最大值狀況 
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
        	//當num沒被線段數記錄過(或被重置過)，則記錄下來 
        	if(num[n]==0)	
			{
        		k=n;
				update(1,1,10000);
			} 
        	num[n]++;//數字num次數增加一次
			nums++;//總數字增加 
        }
    }
    cout<<endl;
    return 0;
}