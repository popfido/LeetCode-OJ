class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        const int n = s.size();
        int dpMin[n + 1];
        vector<vector<bool>> dpCut = vector<vector<bool>>(n,vector<bool>(n,false));
        for (auto i=0; i<=n;i++)
            dpMin[i] = n - i - 1;
        
        for (auto i=n-1;i>=0;i--)
            for (auto j=i;j<n;j++)
                if(s[i]==s[j] && (j-i<2||dpCut[i+1][j-1])){
                    dpCut[i][j] = true;
                    dpMin[i] = min(dpMin[j+1]+1, dpMin[i]);
                }
                
        return dpMin[0];
    }
};


