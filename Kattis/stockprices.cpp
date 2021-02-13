#include<iostream>
#include<queue>
using namespace std;

struct Stock{
    int shares;
    int price;
    bool operator < (const Stock &x) const{
        return price == x.price ? shares > x.shares : price < x.price;
    }
    bool operator > (const Stock &x) const{
        return price == x.price ? shares > x.shares : price > x.price;
    }
    Stock(){
        shares = 0;
        price = 0;
    }
    Stock(int a, int b){
        shares = a;
        price = b;
    }
}tmpStock;

int T, n, shrs, prcs, lD;
priority_queue<Stock, vector<Stock>, greater<Stock> > sellOrder;
priority_queue<Stock> buyOrder;
string strA, strB, strC;

void Print(int lastDeal){
    if(sellOrder.empty()){
        cout << '-';
    }else{
        cout << sellOrder.top().price;
    }
    cout << ' ';
    if(buyOrder.empty()){
        cout << '-';
    }else{
        cout << buyOrder.top().price;
    }
    cout << ' ';
    if(lastDeal == -1){
        cout << '-';
    }else{
        cout << lastDeal;
    }
    cout << '\n';
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    cin >> T;
    while(T--){
        lD = -1;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> strA >> shrs >> strB >> strC >> prcs;
            if(strA == "buy"){
                buyOrder.push(Stock(shrs, prcs));
            }else{
                sellOrder.push(Stock(shrs, prcs));
            }
            
            while(!buyOrder.empty() && !sellOrder.empty() && buyOrder.top().price >= sellOrder.top().price){
                lD = sellOrder.top().price;
                if(buyOrder.top().shares > sellOrder.top().shares){
                    tmpStock = buyOrder.top();
                    tmpStock.shares -= sellOrder.top().shares;

                    buyOrder.pop();
                    sellOrder.pop();

                    buyOrder.push(tmpStock);
                }else if(buyOrder.top().shares < sellOrder.top().shares){
                    tmpStock = sellOrder.top();
                    tmpStock.shares -= buyOrder.top().shares;

                    sellOrder.pop();
                    buyOrder.pop();
                    
                    sellOrder.push(tmpStock);
                }else{
                    buyOrder.pop();
                    sellOrder.pop();
                }
            }
            Print(lD);
        }
        while(!sellOrder.empty()){
            sellOrder.pop();
        }
        while(!buyOrder.empty()){
            buyOrder.pop();
        }
    }
    return 0;
}