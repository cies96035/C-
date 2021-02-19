#include<iostream>
#include<algorithm>
using namespace std;

int alphabet[3];
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i = 0; i < 3; i++){
        cin >> alphabet[i];
    }
    sort(alphabet, alphabet + 3);
    for(int i = 0; i < 2; i++){
        cin >> c;
        cout << alphabet[c - 'A'] << ' ';
    }
    cin >> c;
    cout << alphabet[c - 'A'] << '\n';

    return 0;
}