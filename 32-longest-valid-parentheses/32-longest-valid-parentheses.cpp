class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int maxlen =0 , len =0;
        st.push(-1);
        if(s == ""){
            return 0;
        }
        for(int i=0;s[i]!='\0';i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                st.pop();
                if(!st.empty()){
                    len = i-st.top();
                    maxlen = max(len,maxlen);
                }
                else{
                    st.push(i);
                }
            }
            
        }
        return maxlen;
    }
};