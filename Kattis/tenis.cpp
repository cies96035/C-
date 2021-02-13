#include<iostream>
#include<sstream>
using namespace std;

int StringToNum(string s){
    int n = 0;
    for(auto c : s){
        n = 10 * n + c - '0';
    }
    return n;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int gameTimes, paScore, pbScore;
    int paScoreCnt, pbScoreCnt, N;
    bool error;
    
    string PA, PB, tmp;
    stringstream ss;
    cin >> PA >> PB;
    cin >> N;
    cin.ignore();

    for(int i = 0; i < N; i++){

        paScoreCnt = pbScoreCnt = gameTimes = error = 0;

        getline(cin, tmp);
        
        ss.clear();
        ss << tmp;

        while(ss >> tmp){

            gameTimes++;
            if(paScoreCnt >=2 || pbScoreCnt >= 2){
                error = true;
            }

            for(int i = 0; i < tmp.size(); i++){
                if(tmp[i] == ':'){
                    paScore = StringToNum(tmp.substr(0, i));
                    pbScore = StringToNum(tmp.substr(i + 1, tmp.size() - i - 1));
                    break;
                }
            }


            if(paScore > pbScore){
                paScoreCnt++;
            }else{
                pbScoreCnt++;
            }

            if(pbScore < paScore){
                swap(paScore, pbScore);
            }
            

            if(gameTimes != 3){
                if(paScore <= 4 && pbScore != 6){
                    error = true;
                }else if( (paScore == 5 || paScore == 6) && pbScore != 7){
                    error = true;
                }else if(paScore > 6){
                    error = true;
                }
            }else{
                if(paScore <= 4 && pbScore != 6){
                    error = true;
                }else if(paScore > 4 && pbScore - paScore != 2){
                    error = true;
                }
            }

            
            
        }
        if( (paScoreCnt < 2 && pbScoreCnt < 2) || paScoreCnt == pbScoreCnt){
            error = 1;
        }

        if(error){
            cout << "ne\n";
        }else if(paScoreCnt && PB == "federer"){
            cout << "ne\n";
        }else if(pbScoreCnt && PA == "federer"){
            cout << "ne\n";
        }else{
            cout << "da\n";
        }
    }
    return 0;
}
