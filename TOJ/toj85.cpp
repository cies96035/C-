#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

inline int toid(char x){
    return x - 'A';
}
struct NODE{
    NODE* next[26] = {0};
    bool illed;
    string ill;
    NODE():illed(false){}
}*root;
void Init(){
    root = new NODE;
}
void Insert(NODE *cur, int Id, const string &word, const string &ill){
    if(word.size() == Id){
        cur->ill = ill;
        cur->illed = true;
        return;
    }
    if(cur->next[ toid(word[Id]) ]){
        Insert(cur->next[ toid(word[Id]) ], Id + 1, word, ill);
    }else{
        cur->next[ toid(word[Id]) ] = new NODE;
        Insert(cur->next[ toid(word[Id]) ], Id + 1, word, ill);
    }
    return;
}
void InsertWord(string word, string ill){
    Insert(root, 0, word, ill);
}
string Ask(string word){
    NODE* cur = root;
    for(auto c : word){
        cur = cur->next[ toid(c) ];
        if(cur == nullptr){
            return "Not found!";
        }
    }
    if(cur->illed){
        return cur->ill;
    }else{
        return "Not found!";
    }
}