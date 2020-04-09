#include<iostream>
using namespace std;
 
int main() {
	int a[2],b[2],c[2],d,e;
	cin>>a[0]>>b[0]>>c[0]>>d>>e;
	a[1]=a[0]-2*e;
	b[1]=b[0]-2*e;
	c[1]=c[0]-2*e;
 
	int area1=2*(b[0]*c[0]+a[0]*c[0]+a[0]*b[0]),
	area2=8*(a[1]+b[1]+c[1])*d;
	cout<<area1+area2<<endl;
 
	int volume1=a[0]*b[0]*c[0],
	volume2=2*(b[1]*c[1]+a[1]*c[1]+a[1]*b[1])*d;
	cout<<volume1-volume2<<endl;
 
	return 0;
}
 
