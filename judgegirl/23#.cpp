#include<iostream>
using namespace std;
 
int max(int *iptr[], int n)
{
	//array[]->��
	//&array[]=iptr[]->array����m
	//iptr->iptr����m
	int m=-2e9;
	for(int** i=iptr;i<iptr+n;i++)
		if(m<**(i))m=**(i);
	return m;
}
int main() {
	int n, i;
    int array[100];
    int *iptr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[(i + 3) % n]));
        iptr[i] = &(array[(i + 3) % n]);
    }
    printf("%d\n", max(iptr, n));
	return 0;
}
 
