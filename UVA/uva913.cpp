#include<iostream>
using namespace std;

/*
觀察每列最後一個數 
第N列的最後一個數比N-1多了(2N-1)2
倒數第二個數、倒數第三個數也是
因此第N列倒數三數的和會比第N-1列多出(2N-1)2*3
題目是給第N列的數字數量，2N-1=題目給的值
*/
int main()
{
	long long N;
	while(cin>>N)
		cout<<(3*N*N+6*N+3)/2-9<<endl;
	return 0;
}
