#include<iostream>
using namespace std;

int main() {
	//113335�A���ڦn���O�έp��������Ѫ�...
	//i:�k��Ψ�l�ƶq,�`�M,s�C�Ӥk�઺��l 
	int i=1,ans=0,s=1;
	while(i<=30)
	{
		//�`�M+=��l+�k��+�]�l 
		ans+=1+i+i*s;
		i++;
		s+=i;
	}
	cout<<ans<<endl;
}
