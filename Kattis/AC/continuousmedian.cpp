#include<iostream>
#include<queue>
using namespace std;
using ll = long long;


int T;
int n, num;
ll sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        priority_queue<int, vector<int>, greater<int>> rightPart;
        priority_queue<int> leftPart;
        sum = 0;

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> num;
            leftPart.push(num);
            if(leftPart.size() > rightPart.size()){
                rightPart.push( leftPart.top() );
                leftPart.pop();
            }

            if(i >> 1){
                if(leftPart.top() > rightPart.top()){
                    rightPart.push(leftPart.top());
                    leftPart.push(rightPart.top());
                    rightPart.pop();
                    leftPart.pop();
                }
            }
            if(i & 1){
                sum += ( leftPart.top() + rightPart.top() ) / 2;
            }else{
                sum += rightPart.top();
            }
        }
        cout << sum << '\n';
    }
    return 0;
}