#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

const int MAX_N = 110;
const int days[13] = {
    0, 31, 59, 90,
    120, 151, 181, 212, 243,
    273, 304, 334, 365
};

int n;
string name;
int M, D;
char c;
int date[MAX_N];
int longest;
int longestDay;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name >> M >> c >> D;
        date[i] = days[M - 1] + D - 1;
    }
    sort(date, date + n);
    longest = date[0] - date[n - 1] + 365;
    longestDay = date[0];

    for(int i = 1; i < n; i++){
        if(date[i] - date[i - 1] > longest){
            longest = date[i] - date[i - 1];
            longestDay = date[i];
        }else if(date[i] - date[i - 1] == longest &&
            (date[i] + 64) % 365 < (longestDay + 64) % 365
        ){
            longestDay = date[i];
        }
    }
    longestDay = (longestDay + 364) % 365;
    for(int i = 0; i < 13; i++){
        if(longestDay < days[i]){
            cout << setfill('0');
            cout << setw(2)  << i << '-' << setw(2)  << longestDay - days[i - 1] + 1 << '\n';
            break;
        }
    }
    return 0;
}