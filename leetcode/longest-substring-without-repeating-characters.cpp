class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool used[256];
        for(int i = 0; i < 256; i++){
            used[i] = false;
        }
        int l = 0, r = 0;
        int ans = 0;
        for(auto c : s){
            r++;
            if(used[c]){
                while(s[l] != c){
                    used[ s[l] ] = false;
                    l++;
                }
                l++;
            }else{
                used[c] = true;
                if(r - l > ans){
                    ans = r - l;
                }
            }
        }
        return ans;
    }
};