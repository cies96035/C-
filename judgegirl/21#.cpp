#include<iostream>
using namespace std;
 
int max(int array[5][5])
{
	int m=-2e9;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(m<array[i][j])m=array[i][j];
	return m;
}
int main() {
    int i, j;
    int array[5][5];
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
              scanf("%d", &(array[i][j]));
      printf("%d\n", max(array));
	return 0;
}
