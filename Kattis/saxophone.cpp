#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int cnt[10];
    bool pressed[10];
    int t;
    map<char, int> Fingers;
    {
        Fingers['c'] = 0;
        Fingers['d'] = 1;
        Fingers['e'] = 2;
        Fingers['f'] = 3;
        Fingers['g'] = 4;
        Fingers['a'] = 5;
        Fingers['b'] = 6;
        Fingers['C'] = 7;
        Fingers['D'] = 8;
        Fingers['E'] = 9;
        Fingers['F'] = 10;
        Fingers['G'] = 11;
        Fingers['A'] = 12;
        Fingers['B'] = 13;
    }
    bool fingersTable[14][10] =
    {
        0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
        0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
        0, 1, 1, 1, 0, 0, 1, 1, 0, 0,
        0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
        0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0,

        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,

        1, 1, 1, 1, 0, 0, 1, 1, 1, 0,
        1, 1, 1, 1, 0, 0, 1, 1, 0, 0,
        1, 1, 1, 1, 0, 0, 1, 0, 0, 0,
        1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    cin >> t;
    cin.ignore();
    string Str;
    while(t--)
    {
        memset(pressed, 0, sizeof(pressed));
        memset(cnt, 0, sizeof(cnt));
        getline(cin, Str);
        for(auto s : Str)
        {
            for(int i = 0; i < 10; i++)
            {
                bool p = fingersTable[Fingers[s]][i];
                if(p != pressed[i]){
                    if(pressed[i]){
                        pressed[i] = 0;
                    }else{
                        pressed[i] = 1;
                        cnt[i]++;
                    }
                }
            }
        }
        cout << cnt[0];
        for(int i = 1; i < 10; i++)
            cout << ' ' << cnt[i];
        cout << '\n';
    }
    return 0;
}