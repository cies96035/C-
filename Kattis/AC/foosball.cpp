#include<iostream>
#include<queue>
#include<vector>

using namespace std;
using pii = pair<int,int>;

const int MAX_N = 15;
int N;
string name[MAX_N];
queue<int> people;
vector<pii> team;
int blackDynasty, whiteDynasty, MaxDynasty;
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int WO = 0, BO = 1, WD = 2, BD = 3;
    int LB = 3, LW = 2;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> name[i];
    }
    
    for(int i = 4; i < N; i++){
        people.push(i);
    }

    while(cin >> c){
        if(c == 'W'){
            swap(WO, WD);

            people.push(BD);
            BD = BO;
            BO = people.front();
            LB = BO;
            people.pop();

            whiteDynasty++;
            blackDynasty = 0;

            if(whiteDynasty > MaxDynasty){
                MaxDynasty = whiteDynasty;
                team.clear();
                if(WO == LW){
                    team.emplace_back(pii(WD, WO));
                }else{
                    team.emplace_back(pii(WO, WD));
                }
            }else if(whiteDynasty == MaxDynasty){
                if(WO == LW){
                    team.emplace_back(pii(WD, WO));
                }else{
                    team.emplace_back(pii(WO, WD));
                }
            }
            
        }else if(c == 'B'){
            swap(BO, BD);

            people.push(WD);
            WD = WO;
            WO = people.front();
            LW = WO;
            people.pop();

            blackDynasty++;
            whiteDynasty = 0;

            if(blackDynasty > MaxDynasty){
                MaxDynasty = blackDynasty;
                team.clear();
                if(BO == LB){
                    team.emplace_back(pii(BD, BO));
                }else{
                    team.emplace_back(pii(BO, BD));
                }
            }else if(blackDynasty == MaxDynasty){
                if(BO == LB){
                    team.emplace_back(pii(BD, BO));
                }else{
                    team.emplace_back(pii(BO, BD));
                }
            }

        }
    }
    for(vector<pii>::iterator i = team.begin();i != team.end();i++){
        cout << name[i->first] << ' ' << name[i->second] << '\n';
    }
    
    return 0;
}

/*
02 13 45
20 41 53
02 54 31
30 45 12
03 51 24

*/