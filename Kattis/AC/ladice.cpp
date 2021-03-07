#include<iostream>
using namespace std;

const int MAX_NL = 300300;
int N, L, A, B;

int dset[MAX_NL];
int dsetSize[MAX_NL];
int dsetCnt[MAX_NL];

void Init(int L){
    for(int i = 0; i <= L; i++){
        dset[i] = i;
        dsetSize[i] = 1;
    }
}

int find(int x){
    return dset[x] == x ? x : dset[x] = find(dset[x]);
}

bool Union(int a, int b){
    if(find(a) != find(b)){
        dsetCnt[find(b)] += dsetCnt[find(a)]; 
        dsetSize[find(b)] += dsetSize[find(a)];
        dset[find(a)] = find(b);
    }
    if(dsetCnt[find(b)] < dsetSize[find(b)]){
        dsetCnt[find(b)]++;
        return true;
    }else{
        return false;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> L;

    Init(L);
    while(N--){
        cin >> A >> B;
        if( Union(A, B) ){
            cout << "LADICA\n";
        }else{
            cout << "SMECE\n";
        }

    }
    return 0;
}