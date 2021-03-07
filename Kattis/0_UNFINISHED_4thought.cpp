#include<iostream>
#include<stack>
using namespace std;

const int MAX_N = 1000100;
int *count = new int[2 * MAX_N] + MAX_N;

int tryCount(int op){
    /*int op[3] = 
    {
        op / 16,
        (op / 4) % 4,
        op % 4
    };*/
    stack<int> Op;
    stack<int> num;
    Op.push( op / 16 );
    Op.push( (op / 4) % 4 );
    Op.push( op % 4);
    for(int i = 0; i < 4; i++){
        num.push(4);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    return 0;
}