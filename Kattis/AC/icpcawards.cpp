#include<iostream>
#include<set>
using namespace std;

int N;
int awardCnt;
string school, team;
set<string> awardSchool;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> school >> team;
        if(awardCnt < 12 && awardSchool.find(school) == awardSchool.end()){
            cout << school << ' ' << team << '\n';
            awardCnt++;
        }
        awardSchool.insert(school);
    }
    return 0;
}