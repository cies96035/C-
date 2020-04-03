#include<iostream>
#include<algorithm>
using namespace std;

//數學題
/*
依題意需求知道要求 
(X1-x)^2+(Y1-y)^2+(X2-x)^2+(Y2-y)^2...的最小值x,y
可轉換成|X1-x|+|X2-x|+|X3-x|..得最小值x
和|Y1-y|+|Y2-y|+|Y3-y|...的最小值y 
*/ 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t,F;
	cin>>t;
	while(t--)
	{
		//S,A 用不到 
		cin>>F>>F>>F;
		int S[F+1],A[F+1];
		for(int i=0;i<F;i++)
			cin>>S[i]>>A[i];
		sort(S,S+F);
		sort(A,A+F);
		if(F%2)//odd
			cout<<"(Street: "<<S[F/2]<<", Avenue: "<<A[F/2]<<")\n";
		else //even
			cout<<"(Street: "<<S[F/2-1]<<", Avenue: "<<A[F/2-1]<<")\n";
	}
	return 0;
}
