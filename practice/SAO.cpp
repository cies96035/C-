#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
#define SystemCall system
#define Switch(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
#define StayCool(x) Sleep(x);

inline void MottoHayaku(const char &c,const ui &x)
{
    StayCool(x);
    cout<<c;
    return;
}

class SAO
{
    public:
        SAO() : Tr("00000rt0000000sabemu") , path(2716948169451){}
        void UGO()
        {
            static int c=0;
            c++;
            if(!(10%c)&&c^2)
                MottoHayaku(this->Beater()-32,400);
            else
                MottoHayaku(this->Beater(),200);
            return;
        }
    protected:
        const string Tr;
        ull path;
        char Beater()
        {
            ui s=1;
            for( ; this->Tr[s]=='0' ; path>>=1)
                s = path&1 ? s*2+1 : s<<1;
            return this->Tr[s];
        }
};

int main()
{
    cin.tie(0);
    //ios_base::sync_with_stdio(0);
    
    string done("!!!!!!!!!\nIs it...all over...?\n");
    SAO kiritokun;
    ui Time=16;

    Switch(3);

    while(Time --> 0)
        Time!=6 ? kiritokun.UGO() : MottoHayaku(' ',200);
    for(ui i=0;i<done.size();i++)
        MottoHayaku(done[i],200);
    SystemCall("PAUSE");
    return 0;
}