class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if(ans > 2147483647 || ans < -2147483648){
            return 0;
        }
        return ans;
    }
};