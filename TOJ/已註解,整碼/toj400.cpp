#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


long long strtolong(string a)
{
	long long sum=0,as=a.size();
	for(int i=0;i<as;i++)
		sum=sum*10+a[i]-'0';
	return sum;
}

int main() {
	string Number;
	cin>>Number;
	if(Number[0]<='9')//�O�Ʀr���ܡA�ഫ���^���r 
	{
		//����r���ഫ��long long�H�Q�p�� 
		long long num=strtolong(Number),digits=51;
		bool isget[52];//�x�s��ܭ��Ӧr���n�X�{ 
		memset(isget,0,sizeof(isget));
		while(num)//����num�k�s����A�q�̰��챽��̧C��A�P�_�O�_�X�{�Ӧr�� 
		{
			if(pow(2,digits)<=num)
			{
				num-=pow(2,digits);
				isget[digits]=1;
			} 
			digits--;
		}
		//��X 
		for(int i=0;i<26;i++)
			if(isget[i])
				cout<<char('A'+i);
		for(int i=26;i<52;i++)
			if(isget[i])
				cout<<char('a'+i-26);
		cout<<endl;
	}
	else//�N�r���ন�Ʀr 
	{
		//A�N��2^0,B�N��2^1...a�N��2^26�A�N�ɤO�ѴN�n 
		long long sum=0;
		for(int i=0;i<Number.size();i++)
		{
			if(Number[i]>='a')
				sum+=pow(2,Number[i]-'a'+26);
			else
				sum+=pow(2,Number[i]-'A');
		}
		cout<<sum<<endl;
	}
	return 0;
}
