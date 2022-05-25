class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //ASCII values of not more than 256 therefore made an array of 256
        vector<int> dict(256,-1);
        int maxlen=0, start =-1;
        for(int i=0;i<s.length();i++){
            if(dict[s[i]]>start){
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxlen = max(maxlen,i-start);
        }
        return maxlen;
    }
};