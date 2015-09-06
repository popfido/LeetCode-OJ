class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int> > ret;
        if(nums.size()==0)
            return ret;
            
        vector<int> curr;
        vector<bool> isVisited(nums.size(),false);
        
        /* we need to sort the input array here because of this array
           contains the duplication value, then we need to skip the duplication
           value for the final result */
        sort(nums.begin(), nums.end());

        backtracking(ret, curr, isVisited, nums);
        return ret;
    }
    
    void backtracking(vector<vector<int>>& ret, vector<int>& curr, vector<bool>& isVisited, vector<int>& nums){
        if(curr.size()==nums.size()){
            ret.push_back(curr);
            return;
        }
        
        for(auto i=0;i<nums.size();i++){
            if(!isVisited[i]){
                isVisited[i] = true;
                curr.push_back(nums[i]);
                backtracking(ret, curr, isVisited, nums);
                isVisited[i] = false;
                curr.pop_back();
                while(i<nums.size()-1 && nums[i] == nums[i+1])
                    i++;
            }
        }
    }
};
