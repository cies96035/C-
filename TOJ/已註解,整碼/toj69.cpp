#include<iostream>
using namespace std;
int main(){
    unsigned long long K,N;
    cin>>K>>N;
    //cout<<K*N-1<<endl;//會有溢位問題，有機率WA
	cout<<K*(N-1)-1+K<<endl;//正解 
}
