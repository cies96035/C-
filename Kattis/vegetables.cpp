#include<iostream>
#include<set>
using namespace std;
using ld = long double;

const int MAX_N = 1010;

ld T;
int N;
int vegtables;
int cutAmount;

struct Vegetables{
    ld weight;
    ld cuts;
    ld id;
    bool operator <(const Vegetables &x)const{
        return (weight / cuts) == (x.weight / x.cuts) ? id < x.id : (weight / cuts) < (x.weight / x.cuts) ;
    }
    Vegetables(int a, int b, int c){
        weight = a;
        cuts = b;
        id = c;
    }
    Vegetables(){}
}tmp;
set<Vegetables> boil;

ld GetRatio(Vegetables a, Vegetables b){
    return (a.weight / a.cuts) / (b.weight / b.cuts);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T >> N;
    for(int i = 0; i < N; i++){
        cin >> vegtables;
        boil.insert( Vegetables(vegtables, 1, i) );
    }


    while(GetRatio( *boil.begin(), *( --boil.end() )) < T ){
        tmp = *(--boil.end());
        boil.erase(--boil.end());
        tmp.cuts++;
        boil.insert(tmp);
        cutAmount++;
    }
    cout << cutAmount << '\n';
    return 0;
}