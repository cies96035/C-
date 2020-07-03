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

int line_amount[Max],line_amount_index=2;
int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  //Init
  for(int i=1;i<Max;i++)
  line_amount[line_amount_index]=line_amount[line_amount_index++]+i;
  int term,TA;//Total amount

  while(cin>>term)
  {
    cout<<"TERM "<<term<<" IS ";
    TA=lower_bound(line_amount,line_amount+line_amount_index,term)-line_amount-1;
    term-=line_amount[TA];
    if(TA%2)
      cout<<term<<'/'<<TA-term<<'\n';
    else
      cout<<TA-term<<'/'<<term<<'\n';
  }
  return 0;
}
