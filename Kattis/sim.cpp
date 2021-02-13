#include<iostream>
#include<list>
using namespace std;

list<char> lc;
list<char>::iterator lci;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    char c;
    cin >> T;
    cin.ignore();
    lci = lc.begin();

    while(T && cin.get(c)){
        if(c == '[' || c == ']' || c == '\n'){
            if(c == '['){
                lci = lc.begin();
            }else if(c == ']'){
                lci = lc.end();
            }else{
                for(auto ch : lc){
                    cout << ch;
                }
                cout << '\n';
                lc.clear();
                lci = lc.begin();
                T--;
            }
        }else if(c == '<'){
            if(lci != lc.begin()){
                lci = lc.erase(--lci);
            }
        }else{
            lc.insert(lci, c);
        }
    }
    return 0;
}