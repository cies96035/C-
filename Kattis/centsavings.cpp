#include<iostream>
#include<climits>
using namespace std;

const int MAX_N = 2020;
const int MAX_D = 22;

int n, d;
int sum;
int goods[MAX_N];
int prices[MAX_D];
int cutPlace[MAX_D], cutid;
int presum[MAX_N];
int tmp;


int inSum(int a, int b){
    return presum[b + 1] - presum[a];
}
void Cut(){
    int min = INT_MAX, minid;
    for(int i = 0, j; i < n; i++){
        /*while(cutPlace[j] >= i){
            j++;
        }*/
        //if(premin > )
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        cin >> goods[i];
        sum += goods[i];
    }
    for(int i = 0)
    
    return 0;
}

/*
3 1 5 0 2


*/