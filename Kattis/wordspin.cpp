#include<iostream>
#include<queue>
using namespace std;

string s1;
string s2;
int tmp;
int cnt;

void getCnt(int s, int e){
    if(s >= e){
        return;
    }
    //cout <<s <<' '<<e<<endl;
    int Min = 1000000;
    for(int i = s; i < e; i++){
        if(std::abs(s2[i]) < std::abs(Min)){
            Min = s2[i];
        }
    }
    //cout<<Min<<endl;
    for(int i = s; i < e; i++){
        s2[i] -= Min;
    }
    cnt += std::abs(Min);

    //cout << s<<' '<<e<<endl;
    for(int i = s, ss; i < e;){
        if(s2[i] == 0){
            i++;
            //continue;
        }
        ss = i;
        while(i < e && s2[i]){
            i++;
        }
        getCnt(ss, i);
        /*for(int j = i + 1; j <= e; j++){
            if(j < e && s2[j] == 0){
                getCnt(i, j);
                i = j;
                break;
            }else if(j == e){
                getCnt(i, j);
                i = j;
                break;
            }
        }*/
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++){
        s2[i] -= s1[i];
        //cout << int(s2[i]) << ' ';
    }
    //cout << endl;
    //getCnt(0, s2.size());
    
    for(int i = 0, s; i < s1.size();){
        while(s2[i] == 0){
            i++;
        }
        s = i;
        while(i < s1.size() && s2[s] * s2[i] > 0){
            i++;
        }

        getCnt(s, i);

        /*
        for(int j = i + 1; j <= s1.size(); j++){
            if(j < s1.size() && s2[i] * s2[j] <= 0){
                
                cout << i <<'a'<<j<<endl;
                cout<<int(s2[i])<<'n'<<int(s2[j])<<endl;
                getCnt(i, j);
                i = j;
                break;
            }else if(j == s1.size()){
                //cout <<i <<'x'<<j<<endl;
                getCnt(i, j);
                i = j;
            }
        }*/
    }
    cout << cnt << '\n';
    return 0;
}

/*

-25 ~ 25
25 = -1
13 = -13

-12 12
-1 -1 -1
*/
