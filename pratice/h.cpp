#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)//��X�@n�h 
	{ 
		for(int j=0;j<i;j++)//�C�h��Xi��
			cout<<i;//�C�h��Xi 
		cout<<endl;
	} 
	return 0;
}

