#include<iostream>
#include<algorithm>
using namespace std;
#define Max 5000

/*
2: 1,1
3: 1,2 2,1 *
4: 3,1 2,2 1,3
5: 1,4 2,3 3,2 4,1 *
*/

int term[Max],termindex=2;
int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  //Init
  for(int i=1;i<Max;i++)
  term[termindex]=term[termindex++]+i;
  int N,amount;
  while(cin>>N)
  {
    cout<<"TERM "<<N<<" IS ";
    amount=lower_bound(term,term+termindex,N)-term-1;
    N-=term[amount];
    if(amount%2)
      cout<<N<<'/'<<amount-N<<'\n';
    else
      cout<<amount-N<<'/'<<N<<'\n';
  }
  return 0;
}
