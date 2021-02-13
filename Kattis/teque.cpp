#include<iostream>
#include<deque>
using namespace std;

int t, x;
string op;
deque<int> L, R;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> op >> x;
        if(op == "push_back"){
            R.push_back(x);
            if(R.size() > L.size()){
                L.push_back(R.front());
                R.pop_front();
            }
        }else if(op == "push_front"){
            L.push_front(x);
            if(L.size() == R.size() + 2){
                R.push_front(L.back());
                L.pop_back();
            }
        }else if(op == "push_middle"){
            if(R.size() >= L.size()){
                L.push_back(x);
            }else{
                R.push_front(x);
            }
        }else{
            if(x < L.size()){
                cout << L[x] << '\n';
            }else{
                x -= L.size();
                cout << R[x] << '\n';
            }
        }
    }
    return 0;
}