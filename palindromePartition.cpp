class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        const int n = s.length();
        vector<vector<bool>>dp = vector<vector<bool>>(n,vector<bool>(n,false));
        for (int i=n-1;i>=0;i--)
            for(int j=i; j<n;j++)
                dp[i][j] = s[i]==s[j] && ((j-i<2)||dp[i+1][j-1]);
        
        vector<vector<string>> sub_palins[n];
        
        for(int i=n-1;i>=0;i--)
            for(int j=i;j<n;j++){
                if(dp[i][j]){
                    string palindrome = s.substr(i,j-i+1);
                    if(j+1<n){
                        for(auto v:sub_palins[j+1]){
                            v.insert(v.begin(),palindrome);
                            sub_palins[i].push_back(v);
                        }
                    }
                    else
                        sub_palins[i].push_back(vector<string> {palindrome});
                }
            }
        return sub_palins[0];
    }
};
