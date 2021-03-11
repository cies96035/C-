#include<iostream>
#include<set>
using namespace std;

int P, N;
string str;
set<string> boat;
int day;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> P >> N;
    for(int i = 1; i <= N; i++){
        cin >> str;
        boat.insert(str);
        if(!day && boat.size() == P){
            day = i;
        }
    }
    if(boat.size() != P){
        cout << "paradox avoided\n";
    }else{
        cout << day << '\n';
    }
    return 0;
}