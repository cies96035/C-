//sort練習 

#include<iostream>
#include<algorithm>
using namespace std;

#define len 10

struct point
{
	int x,y;
};

//關於函數傳入值的方式，網路上是說const &a這樣最好，具體原因尚不清楚 
bool smaller(int const &a,int const &b)
{
	if(a>=b)return 1;//如果前面的值>後面的值，就是正確的
	return 0;
}

bool Reverse(int const &a,int const &b)
{
	return 1;
}

//sort好用的地方在於它有方便依條件排序Struct的功能 
bool comparepoint(point const &a,point const &b)
{
	//先比兩個x座標排序，讓x較大者排前面 
	if(a.x>b.x)return 1;
	if(a.x<b.x)return 0;
	
	//x座標都一樣就再比較y座標，讓Y座標較大者排前面 
	if(a.y>b.y)return 1;
	return 0;
}

int main()
{
	int A;
	while(cin>>A)
	{
		int array[len]={8,7,1,11,2,6,4,7,3,4};
		if(A==1)
		{	//不自訂的排序，完整由小到大
			sort(array,array+len); 
			for(int i=0;i<len;i++)cout<<array[i]<<' ';
			cout<<endl<<endl;
		}
		else if(A==2)
		{	//特定區域的排序(3~8) 
			sort(array+3,array+8); 
			for(int i=0;i<len;i++)cout<<array[i]<<' ';
			cout<<endl<<endl;
		}
		else if(A==3)
		{	//自訂由大排到小 
			sort(array,array+len,smaller); 
			for(int i=0;i<len;i++)cout<<array[i]<<' ';
			cout<<endl<<endl;
		}
		else if(A==4)
		{	//倒轉整個陣列 
			sort(array,array+len,Reverse); 
			for(int i=0;i<len;i++)cout<<array[i]<<' ';
			cout<<endl<<endl;
		}
		else
		{	//排序自訂的資料結構 
			point P[6]={{1,2},{2,4},{1,5},{2,3},{3,5},{4,7}};
			sort(P,P+6,comparepoint);
			for(int i=0;i<6;i++)cout<<P[i].x<<','<<P[i].y<<' ';
			cout<<endl<<endl;
		}
	}
	return 0;
}

