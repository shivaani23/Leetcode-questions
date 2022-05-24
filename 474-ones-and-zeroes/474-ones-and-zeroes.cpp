class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        int numzeros,numones;
        for(auto s: strs){
            numzeros = numones = 0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='0') numzeros++;
                else if(s[i]=='1') numones++;
            }
            for(int zero=m;zero>=numzeros;zero--){
                for(int one=n;one>=numones;one--){
                    dp[zero][one] = max(dp[zero-numzeros][one-numones] + 1,dp[zero][one]);
                }
            }
            
        }
        return dp[m][n];
    }
};