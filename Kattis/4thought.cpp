#include<bits/stdc++.h>
using namespace std;

struct OP{
    int a, b, c;
    bool operator < (const OP & x){
        return a == x.a ?
        (b == x.b ? c < x.c : b < x.b) :
        a < x.a;
    }
    OP(){}
    OP(int i, int j, int k):a(i), b(j), c(k){}
};

int tmp;
map<int, OP> moi;
stack<int> op;
queue<int> cal;

int m, n;

char oper[4] = {'+', '-', '*', '/'};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    // 0 +
    // 1 -
    // 2 *
    // 3 /
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){

                cal.push(4);
                op.push(i);
                cal.push(4);
                while(!op.empty() && op.top() / 2 >= j / 2){
                    cal.push(op.top());
                    op.pop();
                }
                op.push(j);
                cal.push(4);
                while(!op.empty() && op.top() / 2 >= k / 2){
                    cal.push(op.top());
                    op.pop();
                }
                op.push(k);
                cal.push(4);
                while(!op.empty()){
                    cal.push(op.top());
                    op.pop();
                }
                while(!cal.empty()){
                    if(cal.front() == 4){
                        op.push(4);
                    }else{
                        tmp = op.top(); op.pop();
                        if(cal.front() == 0){
                            tmp += op.top();
                        }else if(cal.front() == 1){
                            tmp = op.top() - tmp;
                        }else if(cal.front() == 2){
                            tmp *= op.top();
                        }else if(tmp != 0){
                            tmp = op.top() / tmp;
                        }
                        op.pop();
                        op.push(tmp);
                    }
                    cal.pop();
                }
                moi[op.top()] = OP(i, j, k);
                op.pop();
            }
        }
    }

    cin >> m;
    while(m--){
        cin >> n;
        if(moi.find(n) != moi.end()){
            cout << "4 " << oper[ moi[n].a ] << " 4 " <<
            oper[ moi[n].b ] << " 4 " << oper[ moi[n].c ] << " 4 = " << n << '\n';
        }else{
            cout << "no solution\n";
        }
    }
    return 0;
}