#include<iostream>
using namespace std;

char puzzle;
int sum;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> puzzle;
            if(puzzle != '.'){
                puzzle -= 'A';
                sum += std::abs(i - puzzle / 4) + std::abs(j - puzzle % 4);
            }
        }
    }
    cout << sum << '\n';

    return 0;
}