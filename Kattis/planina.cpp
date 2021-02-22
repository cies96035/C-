#include<iostream>
using namespace std;

int N;
const int Table[16] = {
4, 9, 25, 81, 289,
1089, 4225, 16641,
66049, 263169,
1050625, 4198401,
16785409, 67125249,
268468225, 1073807361,
};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    cout << Table[N] << '\n';
    return 0;
}