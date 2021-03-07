#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;

const int MAX_NMK = 100100;
const string JANE = "\"Jane Eyre\"";
struct BOOK{
    string name;
    int page;
    bool operator< (const BOOK x)const{
        return name > x.name;
    }
    BOOK(string n, int p){
        name = n;
        page = p;
    }
    BOOK(){}
}bookTmp;

struct GIFT{
    BOOK book;
    int time;
    bool operator< (const GIFT x)const{
        return time > x.time;
    }
    GIFT(int t, string n, int p){
        time = t;
        book.name = n;
        book.page = p;
    }
    GIFT(){}
}giftTmp;

priority_queue<BOOK> bk;
priority_queue<GIFT> gft;

int giftSize;
int n, m, k;
ll totalTime;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> k;
    cin.ignore();
    for(int i = 0, j, k; i < n; i++){
        getline(cin, bookTmp.name);
        for(j = bookTmp.name.size() - 1; j >= 0; j--){
            if(bookTmp.name[j] == ' '){
                break;
            }
        }
        bookTmp.page = 0;
        for(k = j + 1; k < bookTmp.name.size(); k++){
            bookTmp.page = bookTmp.page * 10 + bookTmp.name[k] - '0';
        }
        bookTmp.name.resize(j);
        bk.push(bookTmp);
    }
    bk.push( BOOK(JANE, k) );

    for(int i = 0, j, k; i < m; i++){
        cin >> giftTmp.time;
        cin.ignore();

        getline(cin, bookTmp.name);
        for(j = bookTmp.name.size() - 1; j >= 0; j--){
            if(bookTmp.name[j] == ' '){
                break;
            }
        }
        bookTmp.page = 0;
        for(k = j + 1; k < bookTmp.name.size(); k++){
            bookTmp.page = bookTmp.page * 10 + bookTmp.name[k] - '0';
        }
        bookTmp.name.resize(j);
        giftTmp.book = bookTmp;

        gft.push(giftTmp);
    }

    while(bk.top().name != JANE){
        totalTime += bk.top().page;
        bk.pop();
        while(!gft.empty() && gft.top().time <= totalTime){
            bk.push(gft.top().book);
            gft.pop();
        }
    }
    cout << totalTime + k << '\n';
    return 0;
}