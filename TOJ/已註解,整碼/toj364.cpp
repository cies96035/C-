#include<iostream>
using namespace std;

#define MaxGear 10100
int N,A,B,mincost=2e9,MaxGearTeeth=0,Gear_cost[MaxGear],Gear[MaxGear],index=0;
bool have_ans=0;

//only need to check Gear on A and Gear on B

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	cin>>N>>A>>B;
	
	//record what teeths have and its lowest_cost
	for(int i=0,teeth,cost;i<N;i++)
	{
		
		cin>>teeth>>cost;
	
		if(!Gear_cost[teeth])//add a new teeth
		{
			Gear_cost[teeth]=cost;
			Gear[index++]=teeth;
		}
		else if(Gear_cost[teeth]>cost)//update teeth's lowest cost
			Gear_cost[teeth]=cost;
			
	}
	
	//if A*Gear[i].teeth = B*Gear[j].teeth ,than it have a ans is Gear[i].cost + Gear[j].cost
	//find there is a Gearteeth equal to other Gearteeth * A / B
	for(int i=0,tmp,cost;i<index;i++)
	{
		//is there have another answer
		if((Gear[i]*A)%B==0 && (tmp=Gear[i]*A/B)<MaxGear && Gear_cost[tmp])
		{
			cost=Gear_cost[tmp]+Gear_cost[Gear[i]];
			if(cost<mincost)//update the minimal cost
				mincost=cost;
			if(have_ans==0)have_ans=1;
		}
	}
	
	
	if(A==B)
		cout<<"0\n";
	else if(have_ans)
		cout<<mincost<<'\n';
	else cout<<"-1\n";
	return 0;
}

