class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        /* DP1 overtime
        auto len = s.size();
        vector<bool> dp(len+1, false);
        dp[0]=true;
        for(auto i=1;i<=len;i++)
            for(auto j=i-1;j>=0;j--)
                if (dp[j] && dict.find(s.substr(j,i-j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
        return dp[len];
        */
        /* DP2 
        vector<bool> f(s.size()+1);
        f[s.size()] = true;
        for (int i = s.size(); --i >= 0; )
            for (auto &w: dict)
                if (i+w.size() <= s.size() && f[i+w.size()] && ! strncmp(&s[i], w.c_str(), w.size())) {
                    f[i] = true;
                    break;
                }
        return f[0];
        */
    }
};
