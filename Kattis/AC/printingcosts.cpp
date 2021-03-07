#include<iostream>
#include<map>
using namespace std;

map<char, int> table;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    {
        table['!'] = 9,
        table['"'] = 6,
        table['#'] = 24,
        table['$'] = 29,
        table['%'] = 22,
        table['&'] = 24,
        table['\''] = 3,
        table['('] = 12,
        table[')'] = 12,
        table['*'] = 17,
        table['+'] = 13,
        table[','] = 7,
        table['-'] = 7,
        table['.'] = 4,
        table['/'] = 10,
        table['0'] = 22,
        table['1'] = 19,
        table['2'] = 22,
        table['3'] = 23,
        table['4'] = 21,
        table['5'] = 27,
        table['6'] = 26,
        table['7'] = 16,
        table['8'] = 23,
        table['9'] = 26,
        table[':'] = 8,
        table[';'] = 11,
        table['<'] = 10,
        table['='] = 14,
        table['>'] = 10,
        table['?'] = 15,
        table['@'] = 32,
        table['A'] = 24,
        table['B'] = 29,
        table['C'] = 20,
        table['D'] = 26,
        table['E'] = 26,
        table['F'] = 20,
        table['G'] = 25,
        table['H'] = 25,
        table['I'] = 18,
        table['J'] = 18,
        table['K'] = 21,
        table['L'] = 16,
        table['M'] = 28,
        table['N'] = 25,
        table['O'] = 26,
        table['P'] = 23,
        table['Q'] = 31,
        table['R'] = 28,
        table['S'] = 25,
        table['T'] = 16,
        table['U'] = 23,
        table['V'] = 19,
        table['W'] = 26,
        table['X'] = 18,
        table['Y'] = 14,
        table['Z'] = 22,
        table['['] = 18,
        table['\\'] = 10,
        table[']'] = 18,
        table['^'] = 7,
        table['_'] = 8,
        table['`'] = 3,
        table['a'] = 23,
        table['b'] = 25,
        table['c'] = 17,
        table['d'] = 25,
        table['e'] = 23,
        table['f'] = 18,
        table['g'] = 30,
        table['h'] = 21,
        table['i'] = 15,
        table['j'] = 20,
        table['k'] = 21,
        table['l'] = 16,
        table['m'] = 22,
        table['n'] = 18,
        table['o'] = 20,
        table['p'] = 25,
        table['q'] = 25,
        table['r'] = 13,
        table['s'] = 21,
        table['t'] = 17,
        table['u'] = 17,
        table['v'] = 13,
        table['w'] = 19,
        table['x'] = 13,
        table['y'] = 24,
        table['z'] = 19,
        table['{'] = 18,
        table['|'] = 12,
        table['}'] = 18,
        table['~'] = 9,
        table[' '] = 0;
    }
    string s;
    int sum;
    while(getline(cin, s)){
        sum = 0;
        for(auto c : s){
            if(table.find(c) != table.end()){
                sum += table[c];
            }
        }
        cout << sum << '\n';
    }
    return 0;
}