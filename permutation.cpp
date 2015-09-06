class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int> > ret;
        
        if(nums.size() == 0)
            return ret;
        
        vector<int> curr;
        vector<bool> isVisited(nums.size(), false);
        backTracking(ret, curr, isVisited, nums);
        return ret;
    }
    
    void backTracking(vector<vector<int>>& ret, vector<int>& curr, vector<bool>& isVisited, vector<int>& nums){
        if(curr.size() == nums.size()){
            ret.push_back(curr);
            return;
        }
        
        for(auto i=0;i<nums.size();i++){
            if (!isVisited[i]){
                isVisited[i] = true;
                curr.push_back(nums[i]);
                backTracking(ret, curr, isVisited, nums);
                isVisited[i] = false;
                curr.pop_back();
            }
        }
        
    }
};

