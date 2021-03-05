#include<iostream>
using namespace std;

int card[2][256];
int N;
char B;
char a, b;
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    card[0]['A'] = card[1]['A'] = 11;
    card[0]['K'] = card[1]['K'] = 4;
    card[0]['Q'] = card[1]['Q'] = 3;
    card[0]['T'] = card[1]['T'] = 10;
    card[0]['J'] = 2;
    card[1]['J'] = 20;
    card[1]['9'] = 14;


    cin >> N >> B;
    
    N *= 4;
    while(N--){
        cin >> a >> b;
        sum += card[b == B][a];
    }
    cout << sum << '\n';
    return 0;
}