#include<iostream>
using namespace std;

/*
count inversion
使用 merge sort >> D&C
參考這裡: 
https://www.youtube.com/watch?v=MxiQa22KrSQ
實作即可 
*/ 

int num[2000000];
long long count=0;


//計算兩個已排列序列的交換數量、並排序兩個序列 
//left~mid左序列,mid+1~right右序列 
void count_inversion(int left,int mid,int right)
{
	int record[right-left+1],//紀錄正確順序用
	leftsub=left,rightsub=mid,//兩個序列的起頭 
	index=0;//記錄用的位置
	
	/*
	由於已排序，最小值必定在兩序列的最左邊其一
	一一比較兩個序列的起頭，並放入紀錄的陣列，即可排出由小到大順序的陣列
	其中當左邊的序列比較大時，計算交換次數 
	*/ 
	//直到其中一個序列沒東西可以比
	while(true)
	{
		if(num[leftsub]<=num[rightsub])
			record[index++]=num[leftsub++];
		else//計算交換次數 
		{
			record[index++]=num[rightsub++];
			count+=mid-leftsub;//影片3:25部分實作 
		}
		//終止條件:直到有左右序列中一個序列紀錄完了，沒得比較時終止
		//並完成紀錄、複製序列(本來是一個區間兩段排完順序的，變成全部排完順序的) 
		if(leftsub==mid)//左序列先紀錄完
		{
			//複製到原陣列 
			while(rightsub<=right)
				record[index++]=num[rightsub++];
			//結束
			break; 
		}
		else if(rightsub>right)//右序列先紀錄完
		{
			while(leftsub<mid)
					record[index++]=num[leftsub++];
			//結束
			break; 
		} 
	}
	for(int i=left,j=0;i<=right;i++,j++)//複製陣列 
		num[i]=record[j];
	return;
}

//遞迴 
void mergesort(int left,int right)
{
	if(left!=right)
	{
		//二分
		int mid=(left+right)/2;
		
		//分成兩半往下處理 
		mergesort(left,mid);
		mergesort(mid+1,right);
		
		//計算交換次數
		count_inversion(left,mid+1,right);
	}
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	mergesort(0,n-1);
	cout<<count<<endl;
	return 0;
}

