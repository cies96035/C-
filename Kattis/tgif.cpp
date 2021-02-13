#include<iostream>
#include<map>
using namespace std;

map<string, int> monthToNum;
map<string, int> dayToNum;
const int days[12] = {
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    monthToNum["JAN"] = 0;
    monthToNum["FEB"] = 1;
    monthToNum["MAR"] = 2;
    monthToNum["APR"] = 3;
    monthToNum["MAY"] = 4;
    monthToNum["JUN"] = 5;

    monthToNum["JUL"] = 6;
    monthToNum["AUG"] = 7;
    monthToNum["SEP"] = 8;
    monthToNum["OCT"] = 9;
    monthToNum["NOV"] = 10;
    monthToNum["DEC"] = 11;
    
    dayToNum["MON"] = 0;
    dayToNum["TUE"] = 1;
    dayToNum["WED"] = 2;
    dayToNum["THU"] = 3;
    dayToNum["FRI"] = 4;
    dayToNum["SAT"] = 5;
    dayToNum["SUN"] = 6;

    int date, month, day;
    string tmp;
    cin >> date;
    cin >> tmp;
    month = monthToNum[tmp];
    date += days[month] - 1;
    cin >> tmp;
    day = dayToNum[tmp];
    if(month >= 2){
        if((date + day) % 7 == 4 || (date + day + 1) % 7 == 4){
            cout << "not sure\n";
        }else{
            cout << ":(\n";
        }
    }else{
        if((date + day) % 7 == 4){
            cout << "TGIF\n";
        }else{
            cout << ":(\n";
        }
    }
    return 0;
}