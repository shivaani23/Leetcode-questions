class Solution {
public:
    string longestPalindrome(string s) {
        //Time complexity -> O(n^2) and space complexity -> O(n)
        int len = s.length();
        string ans;
        int dp[len][len];
        memset(dp,0,sizeof(dp));
        int maxlen=0, x=0;
        if(len==1){
            return s;
        }
        for(int i=0;i<len;i++){
            dp[i][i] =1;
            
            if(s[i]==s[i+1] && i+1<len){
                dp[i][i+1] = 1;
            }
        }
        ans += s[0];
        for(int i=len-1;i>=0;i--){
            for(int j=i+1;j<len;j++){
                if(s[i]==s[j]){
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j] = 1;
                        x = j-i+1;
                        if(maxlen<x){
                            ans = s.substr(i,j-i+1);
                            maxlen = x;
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};