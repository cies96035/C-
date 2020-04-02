#include<iostream>
using namespace std;

int main() {
	//113335，當初我好像是用計算機直接解的...
	//i:女兒及兒子數量,總和,s每個女兒的兒子 
	int i=1,ans=0,s=1;
	while(i<=30)
	{
		//總和+=兒子+女兒+孫子 
		ans+=1+i+i*s;
		i++;
		s+=i;
	}
	cout<<ans<<endl;
}
