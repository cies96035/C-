#include<iostream>
#include<sstream>
#include<map>
using namespace std;

map<string, string> domain;
map<string, string> codomain;
const string Zero = "NOT CONTAIN VALUE";
bool injective;
bool surjective;
bool error;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s, tmp, tmp2;
    stringstream ss;
    int n;
    while(getline(cin, s)){
        error = false;
        surjective = true;
        injective = true;
        domain.clear();
        codomain.clear();

        ss << s;
        ss >> tmp;
        while(ss >> tmp){
            domain[tmp] = Zero;
        }
        ss.clear();

        getline(cin, s);
        ss << s;
        ss >> tmp;
        while(ss >> tmp){
            codomain[tmp] = Zero;
        }
        ss.clear();

        cin >> n;

        while(n--){
            cin >> tmp >> tmp2 >> tmp2;
            if(domain[tmp] != tmp2 && domain[tmp] != Zero){
                error = true;
            }else{
                domain[tmp] = tmp2;
            }

            if(codomain[tmp2] != tmp && codomain[tmp2] != Zero){
                injective = false;
            }else{
                codomain[tmp2] = tmp;
            }
        }

        for(auto str : codomain){
            if(str.second == Zero){
                surjective = false;
            }
        }

        if(error){
            cout << "not a function\n";
        }else if(injective && surjective){
            cout << "bijective\n";
        }else if(injective){
            cout << "injective\n";
        }else if(surjective){
            cout << "surjective\n";
        }else{
            cout << "neither injective nor surjective\n";
        }

        cin.ignore();
    }
    return 0;
}