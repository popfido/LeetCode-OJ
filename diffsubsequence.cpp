class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        vector<int> dp(T.size()+1,0);
        dp[0] = 1;
        for(int i=0; i<S.size();i++)
            for(int j=T.size()-1;j>=0;j--)
                dp[j+1] += S[i]==T[j]?dp[j]:0;
        return dp[T.size()];
    }
};

