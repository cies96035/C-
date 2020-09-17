#include<iostream>
using namespace std;


void swap1(int &a,int &b)
{
	cout<<&a<<endl;
	int tmp=a;
	a=b;
	b=tmp;
	return;
}


void swap2(int *a,int *b)
{
	cout<<a<<endl;
	int tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}



void swap3(int a,int b)
{
	cout<<&a<<endl;
	int tmp=a;
	a=b;
	b=tmp;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int a, b;

	cin>>a>>b;
	cout<<&a<<endl;
	swap2(&a,&b);
	cout<<a<<' '<<b<<endl;
	return 0;
}
