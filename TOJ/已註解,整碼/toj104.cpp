#include <iostream>
using namespace std;

int main() {
    
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)//執行幾排(高度) 
    {
    	for(int j=i;j<N;j++)//補空格，第n排補N-n個空格 
			cout<<' ';
		for(int j=0;j<2*i-1;j++)//第n排輸出2n-1顆星星 
			cout<<'*';
		cout<<endl;
    }
    return 0;
}

