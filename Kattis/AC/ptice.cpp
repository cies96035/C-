#include<iostream>
using namespace std;

int n;
int A, B, G;
int Max;
char c;
char a, b, g;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        a = (i % 3) + 'A';
        b = (i % 2) ? (i / 2) % 2 ? 'C' : 'A' : 'B';
        g = ((i + 4) % 6) / 2 + 'A';
        if(c == a){
            A++;
        }
        if(c == b){
            B++;
        }
        if(c == g){
            G++;
        }
    }
    if(A > Max){
        Max = A;
    }
    if(B > Max){
        Max = B;
    }
    if(G > Max){
        Max = G;
    }

    cout << Max << '\n';
    if(A == Max){
        cout << "Adrian\n";
    }
    if(B == Max){
        cout << "Bruno\n";
    }
    if(G == Max){
        cout << "Goran\n";
    }

    return 0;
}