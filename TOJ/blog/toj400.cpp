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
	if(Number[0]<='9')//是數字的話，轉換成英文單字 
	{
		//先把字串轉換成long long以利計算 
		long long num=strtolong(Number),digits=51;
		bool isget[52];//儲存表示哪個字母要出現 
		memset(isget,0,sizeof(isget));
		while(num)//直到num歸零為止，從最高位掃到最低位，判斷是否出現該字母 
		{
			if(pow(2,digits)<=num)
			{
				num-=pow(2,digits);
				isget[digits]=1;
			} 
			digits--;
		}
		//輸出 
		for(int i=0;i<26;i++)
			if(isget[i])
				cout<<char('A'+i);
		for(int i=26;i<52;i++)
			if(isget[i])
				cout<<char('a'+i-26);
		cout<<endl;
	}
	else//將字母轉成數字 
	{
		//A代表2^0,B代表2^1...a代表2^26，就暴力解就好 
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
