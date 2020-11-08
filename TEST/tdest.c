#include<stdio.h>

int main()
{
  int n,b,k;
  scanf("%d%d",&n,&b);
  k=b;
  while(k<n)
    k*=b;
  k/=b;
  while(k)
  {
    printf("%d",n/k);
    n%=k;
    k/=b;
  }
  printf("\n");
  return 0;
}