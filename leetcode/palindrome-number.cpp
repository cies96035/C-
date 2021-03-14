class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        
        string Test;
        
        while(x){
            Test += x % 10;
            x /= 10;
        }
        
        for(int l = 0, r = Test.size() - 1; l < r; l++, r--){
            if(Test[l] != Test[r]){
                return false;
            }
        }
        
        return true;
    }
};