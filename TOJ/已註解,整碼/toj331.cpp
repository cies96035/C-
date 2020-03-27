#include<iostream>
using namespace std;

int main()
{
	string F,S;
	cin>>F>>S;
	long long Fs=F.size(),Ss=S.size(),
	Fnot0=Fs,Snot0=Ss;//紀錄非零(不用計算)的位數有幾個 
	for(int i=0;i<Fs;i++)if(F[i]=='0')Fnot0--;
	for(int i=0;i<Ss;i++)if(S[i]=='0')Snot0--;
	cout<<Fnot0*Snot0<<endl;
	return 0;
}

