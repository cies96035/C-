#include<iostream>
#include<set>
using namespace std;

struct PIZZA{
    string w1, w2;
    PIZZA(){}
    PIZZA(string a, string b){
        w1 = a;
        w2 = b;
    }
    bool operator< (const PIZZA &x)const{
        return w1 == x.w1 ? w2 < x.w2 : w1 < x.w1;
    }
};
int T;
int t, n;
string ipt;
string strm[30], strn[30];
int mN, nN;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        set<PIZZA> pzz;
        cin >> t;
        while(t--){
            cin >> ipt;
            cin >> mN;
            for(int i = 0; i < mN; i++){
                cin >> strm[i];
            }
            cin >> nN;
            for(int i = 0; i < nN; i++){
                cin >> strn[i];
            }
            for(int i = 0; i < mN; i++){
                for(int j = 0; j < nN; j++){
                    pzz.insert( PIZZA(strm[i], strn[j]) );
                }
            }
        }
        for(auto p : pzz){
            cout << '(' << p.w1 << ", " << p.w2 << ")\n";
        }
        cout << '\n';
    }
    return 0;
}