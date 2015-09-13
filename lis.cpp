class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // DP algorithm
        int n = nums.size();
        int max = 0;
        vector<int>dp(n,1);
        for(auto i=1; i<n;i++){
            for (auto j=0;j<i;j++)
                if(nums[j]<=nums[i] && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            max = dp[i]>max? dp[i]:max;
        }
	    return max;
    }
};

