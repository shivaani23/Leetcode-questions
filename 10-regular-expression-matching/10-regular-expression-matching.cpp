class Solution {
public:
    bool isMatch(string s, string p) {
        bool ans[s.length()+1][p.length()+1];
        int lens = s.length();
        int lenp = p.length();
        
        for(int i=0;i<=lens;i++){
            for(int j=0;j<=lenp;j++){
                if(i==0 && j==0){
                    ans[i][j] = true;
                }
                else if(j==0){
                    ans[i][j] = false;
                }
                else if(i==0){
                    if(p[j-1]== '*'){
                        ans[i][j] = ans[i][j-2];
                    }
                    else{
                        ans[i][j] = false;
                    }
                }
                else{
                    if(p[j-1]=='.' || s[i-1] == p[j-1]){
                    ans[i][j] = ans[i-1][j-1];
                    }
                    else if(p[j-1]=='*'){
                        ans[i][j] = ans[i][j-2];
                        if(p[j-2]=='.' || p[j-2]==s[i-1]){
                            ans[i][j] = ans[i][j] || ans[i-1][j];
                        }
                    }
                    else{
                        ans[i][j] = false;
                    }
                }
                
            }
        }
        return ans[s.length()][p.length()];
    }
};