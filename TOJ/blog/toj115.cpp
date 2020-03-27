#include<iostream>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    string card[10];
    
	for(int i=0;i<10;i++)
		card[i]="EMPTY";
		
    for(int i=0;i<n;i++)
    {
    	int where;
    	string cardname;
        cin>>cardname>>where;
        card[where-1]=cardname;
	}
        
    for(int i=0;i<10;i++)
    	cout<<card[i]<<endl;

    return 0;
}
