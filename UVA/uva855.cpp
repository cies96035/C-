#include<iostream>
#include<algorithm>
using namespace std;

//�ƾ��D
/*
���D�N�ݨD���D�n�D 
(X1-x)^2+(Y1-y)^2+(X2-x)^2+(Y2-y)^2...���̤p��x,y
�i�ഫ��|X1-x|+|X2-x|+|X3-x|..�o�̤p��x
�M|Y1-y|+|Y2-y|+|Y3-y|...���̤p��y 
*/ 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t,F;
	cin>>t;
	while(t--)
	{
		//S,A �Τ��� 
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

