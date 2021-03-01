#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 110;
struct TOYS{
    string name;
    int amount;
    bool operator< (TOYS b){
        return amount == b.amount ? name < b.name : amount > b.amount;
    }
}toys[MAX_N];
bool SortByName (const TOYS &a, const TOYS &b){
    return a.name == b.name ? a.amount < b.amount : a.name < b.name;
}

int toysId;

int T, N;
string name, amount;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        toysId = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> toys[i].name >> toys[i].amount;
        }
        sort(toys, toys + N, SortByName);
        for(int i = 0; i < N; i++){
            if(toys[i].name != toys[i + 1].name){
                toys[toysId++] = toys[i];
            }else{
                toys[i + 1].amount += toys[i].amount;
            }
        }
        sort(toys, toys + toysId);
        cout << toysId << '\n';
        for(int i = 0; i < toysId; i++){
            cout << toys[i].name << ' ' << toys[i].amount << '\n';
        }
    }
    return 0;
}