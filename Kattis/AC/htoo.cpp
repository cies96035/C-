#include<iostream>
#include<climits>
using namespace std;

string S;
int times;
int containAtomAmount[26];
int needAtomAmount[26];
int Min = INT_MAX;

void StringToIntArray(string s, int* array){
    int num = -1;
    int atom;
    s += 'A';
    for(auto c : s){
        if('A' <= c && c <= 'Z'){
            if(num > 0){
                array[atom]+=num;
            }else if(!num){
                array[atom]++;
            }
            atom = c - 'A';
            num = 0;
        }else if('0' <= c && c <= '9'){
            num = num * 10 + c - '0';
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> S >> times;
    StringToIntArray(S, containAtomAmount);
    
    cin >> S;
    StringToIntArray(S, needAtomAmount);

    for(int i = 0, t ; i < 26; i++){
        if(needAtomAmount[i]){
            t = containAtomAmount[i] * times / needAtomAmount[i];
            if(Min > t){
                Min = t;
            }
        }
    }
    cout << Min << '\n';
    return 0;
}